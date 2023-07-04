#ifndef _SERVERREACTOR_H
#define _SERVERREACTOR_H
#include <limits.h>
#include "include/core/platform.h"
#include "include/api/api.h"
#include "include/core/reactor.h"
#include "include/core/reactor_common.h"
#include "include/core/threaded/scheduler.h"
#include "include/core/mixed_radix.h"
#include "include/core/port.h"
#include "include/core/environment.h"
int lf_reactor_c_main(int argc, const char* argv[]);
#include "include/core/federated/federate.h"
#include "include/core/federated/net_common.h"
#include "pythontarget.h"
#include "include/core/reactor.h"
#include <limits.h>
#include "include/core/platform.h"
#include "include/api/api.h"
#include "include/core/reactor.h"
#include "include/core/reactor_common.h"
#include "include/core/threaded/scheduler.h"
#include "include/core/mixed_radix.h"
#include "include/core/port.h"
#include "include/core/environment.h"
int lf_reactor_c_main(int argc, const char* argv[]);
#include "include/core/federated/federate.h"
#include "include/core/federated/net_common.h"
#include "pythontarget.h"
#line 26 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
typedef generic_port_instance_struct _serverreactor_in_parameter_t;
#line 27 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
typedef generic_port_instance_struct _serverreactor_out_parameter_t;
typedef struct {
    struct self_base_t base;
    char *_lf_name;
    PyObject* _lf_py_reaction_function_0;
    PyObject* _lf_py_reaction_function_1;
    #line 28 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    PyObject* large_param;
    #line 26 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    _serverreactor_in_parameter_t* _lf_in_parameter;
    #line 26 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    // width of -2 indicates that it is not a multiport.
    #line 26 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    int _lf_in_parameter_width;
    #line 26 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    // Default input (in case it does not get connected)
    #line 26 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    _serverreactor_in_parameter_t _lf_default__in_parameter;
    #line 27 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    _serverreactor_out_parameter_t _lf_out_parameter;
    #line 27 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    int _lf_out_parameter_width;
    #line 30 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    reaction_t _lf__reaction_0;
    #line 37 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    reaction_t _lf__reaction_1;
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
    #line 26 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    trigger_t _lf__in_parameter;
    #line 26 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    reaction_t* _lf__in_parameter_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
} _serverreactor_self_t;
_serverreactor_self_t* new__serverreactor();
#endif // _SERVERREACTOR_H
