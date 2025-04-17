
#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>

int handle_my_oid(netsnmp_mib_handler *handler,
                  netsnmp_handler_registration *reginfo,
                  netsnmp_agent_request_info *reqinfo,
                  netsnmp_request_info *requests) {
    switch (reqinfo->mode) {
    case MODE_GET:
        snmp_set_var_typed_value(requests->requestvb, ASN_OCTET_STR,
                                 (u_char *)"hello world", strlen("hello world"));
        break;
    default:
        return SNMP_ERR_GENERR;
    }
    return SNMP_ERR_NOERROR;
}

int main(int argc, char **argv) {
    netsnmp_enable_subagent();
    netsnmp_ds_set_boolean(NETSNMP_DS_APPLICATION_ID, NETSNMP_DS_AGENT_ROLE, 1);

    init_agent("myagent");

    oid my_oid[] = { 1,3,6,1,4,1,8072,9999,1 };
    netsnmp_register_scalar(
        netsnmp_create_handler_registration("myOID", handle_my_oid, my_oid,
                                            OID_LENGTH(my_oid), HANDLER_CAN_RONLY));

    init_snmp("myagent");
    while (1) {
        agent_check_and_process(1);
    }

    snmp_shutdown("myagent");
    return 0;
}
