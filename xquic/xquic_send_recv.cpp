#include "xquic_send_recv.hpp"
#include <string.h>


#define def_engine_ssl_config   \
xqc_engine_ssl_config_t  engine_ssl_config;             \
engine_ssl_config.private_key_file = "./server.key";    \
engine_ssl_config.cert_file = "./server.crt";           \
engine_ssl_config.ciphers = XQC_TLS_CIPHERS;            \
engine_ssl_config.groups = XQC_TLS_GROUPS;              \
engine_ssl_config.session_ticket_key_len = 0;           \
engine_ssl_config.session_ticket_key_data = NULL;


void xqc_write_log_default(xqc_log_level_t lvl, const void *buf, size_t count, void *user_data) {return;}
const xqc_log_callbacks_t xqc_null_log_cb = { .xqc_log_write_err = xqc_write_log_default,};
static void null_set_event_timer(xqc_msec_t wake_after, void *engine_user_data) { return;}
static ssize_t null_socket_write(const unsigned char *buf, size_t size, const struct sockaddr *peer_addr, socklen_t peer_addrlen, void *conn_user_data){return size;}

static const xqc_cid_t *
cid_connect(xqc_engine_t *engine)
{
    xqc_conn_settings_t conn_settings;
    ::memset(&conn_settings, 0, sizeof(xqc_conn_settings_t));
    conn_settings.proto_version = XQC_IDRAFT_VER_29;

    xqc_conn_ssl_config_t conn_ssl_config;
    ::memset(&conn_ssl_config, 0, sizeof(conn_ssl_config));
    const xqc_cid_t *cid = xqc_connect(engine, &conn_settings, nullptr, 0, "", 0, &conn_ssl_config,nullptr, 0, "transport", nullptr);
    return cid;
}

static xqc_connection_t *
connect(xqc_engine_t *engine)
{
    const xqc_cid_t *cid = cid_connect(engine);
    if (cid == nullptr) {
        return nullptr;
    }
//    return xqc_engine_conns_hash_find(engine, cid, 's');
}


static xqc_engine_t * create_engine(){
    //create engine
    def_engine_ssl_config;

    xqc_engine_callback_t engine_callback = {
        .log_callbacks = xqc_null_log_cb,
        .set_event_timer = null_set_event_timer,
    };
    xqc_transport_callbacks_t tcbs = {
        .write_socket = null_socket_write,
    };

    xqc_conn_settings_t conn_settings;
    xqc_engine_t *engine = xqc_engine_create(XQC_ENGINE_CLIENT, nullptr, &engine_ssl_config,&engine_callback, &tcbs, nullptr);


    xqc_h3_callbacks_t h3_cbs = {
        .h3c_cbs = {
            .h3_conn_create_notify = nullptr,
            .h3_conn_close_notify = nullptr,
            .h3_conn_handshake_finished = nullptr,
        },
        .h3r_cbs = {
            .h3_request_create_notify = nullptr,
            .h3_request_close_notify = nullptr,
            .h3_request_read_notify = nullptr,
            .h3_request_write_notify = nullptr,
        }
    };

    /* init http3 context */
    int ret = xqc_h3_ctx_init(engine, &h3_cbs);
    if (ret != XQC_OK) {
        xqc_engine_destroy(engine);
        return nullptr;
    }

    /* transport ALPN */
    xqc_app_proto_callbacks_t transport_cbs = {{nullptr}, {nullptr}};
    xqc_engine_register_alpn(engine, "transport", 9, &transport_cbs);

    return  engine;
}



XQuicSR::XQuicSR()
{

}

XQuicSR::~XQuicSR()
{
    TestImpl::stop();
}

void XQuicSR::run()
{



}
