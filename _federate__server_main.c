#include "include/api/api.h"
#include "include/api/set.h"
#include "include/federate__server/federate__server.h"
#include "_federate__server_main.h"
#include "include/api/set.h"
void _federate__server_mainreaction_function_0(void* instance_args) {
    _federate__server_main_main_self_t* self = (_federate__server_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct server {
        _serverreactor_in_parameter_t* in_parameter;
    
    } server;
    // Expose the action struct as a local variable whose name matches the action name.
    _federate__server_main_inputControlReactionTrigger_t* inputControlReactionTrigger = &self->_lf_inputControlReactionTrigger;
    // Set the fields of the action struct to match the current trigger.
    inputControlReactionTrigger->is_present = (bool)self->_lf__inputControlReactionTrigger.status;
    inputControlReactionTrigger->has_value = ((self->_lf__inputControlReactionTrigger.tmplt.token) != NULL && (self->_lf__inputControlReactionTrigger.tmplt.token)->value != NULL);
    _lf_replace_template_token((token_template_t*)inputControlReactionTrigger, (self->_lf__inputControlReactionTrigger.tmplt.token));
    server.in_parameter = &(self->_lf_server.in_parameter);
    #line 63 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    // **** This reaction is unordered.
    interval_t max_STP = 0LL;
    // Wait until the port status is known
    wait_until_port_status_known(self->base.environment, 0, max_STP);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _federate__server_mainreaction_function_1(void* instance_args) {
    _federate__server_main_main_self_t* self = (_federate__server_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct server {
        _serverreactor_in_parameter_t* in_parameter;
    
    } server;
    // Expose the action struct as a local variable whose name matches the action name.
    _federate__server_main_networkMessage_t* networkMessage = &self->_lf_networkMessage;
    // Set the fields of the action struct to match the current trigger.
    networkMessage->is_present = (bool)self->_lf__networkMessage.status;
    networkMessage->has_value = ((self->_lf__networkMessage.tmplt.token) != NULL && (self->_lf__networkMessage.tmplt.token)->value != NULL);
    _lf_replace_template_token((token_template_t*)networkMessage, (self->_lf__networkMessage.tmplt.token));
    server.in_parameter = &(self->_lf_server.in_parameter);
    #line 71 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    // **** This reaction is unordered.
    // Acquire the GIL (Global Interpreter Lock) to be able to call Python APIs.
    PyGILState_STATE gstate;
    gstate = PyGILState_Ensure();
    // **** This reaction is unordered.
    server.in_parameter->physical_time_of_arrival = self->_lf__networkMessage.physical_time_of_arrival;
    PyObject* message_byte_array = PyBytes_FromStringAndSize((char*)networkMessage->token->value, networkMessage->token->length);
    //PyObject* deserialized_message = PyObject_CallMethod(global_pickler, "loads", "O", message_byte_array);
    //PyObject* deserialized_message = PyObject_CallMethod(global_pickler, "ParseFromString", "0", message_byte_array);
    // changed
    PyObject* pb2 = PyObject_CallMethod(global_pickler, "Message", NULL);
    PyObject_CallMethod(pb2, "ParseFromString", "O", message_byte_array);
    PyObject* deserialized_message = PyObject_GetAttrString(pb2, "data");

    if (deserialized_message == NULL) {
        if (PyErr_Occurred()) PyErr_Print();
        lf_print_error_and_exit("Could not deserialize deserialized_message.");
    }
    Py_XDECREF(message_byte_array);
    lf_token_t* token = lf_new_token((void*)server.in_parameter, deserialized_message, 1);
    lf_set_destructor(server.in_parameter, python_count_decrement);
    lf_set_token(server.in_parameter, token);
    /* Release the thread. No Python API allowed beyond this point. */
    PyGILState_Release(gstate);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _federate__server_mainreaction_function_2(void* instance_args) {
    _federate__server_main_main_self_t* self = (_federate__server_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct server {
        _serverreactor_out_parameter_t* out_parameter;
    
    } server;
    server.out_parameter = self->_lf_server.out_parameter;
    #line 93 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    // **** This reaction is unordered.
    // Acquire the GIL (Global Interpreter Lock) to be able to call Python APIs.
    PyGILState_STATE gstate;
    gstate = PyGILState_Ensure();
    // **** This reaction is unordered.
    // Sending from server.out_parameter in federate federate__server to client.in_parameter in federate federate__client
    if (!server.out_parameter->is_present) return;
    if (global_pickler == NULL) lf_print_error_and_exit("The pickle module is not loaded.");
    /* changed
    // PyObject* serialized_pyobject = PyObject_CallMethod(global_pickler, "dumps", "O", server.out_parameter->value);
    // 
    // Create a new message & Serialize the message
    PyObject* message_class = PyObject_GetAttrString(global_pickler, "Message");
    PyObject* pb2 = PyObject_CallObject(message_class, NULL);
    PyObject_SetAttrString(pb2, "data", server.out_parameter->value);
    PyObject* serialized_pyobject = PyObject_CallMethod(pb2, "SerializeToString", NULL); */

    PyObject* pb2 = PyObject_CallMethod(global_pickler, "Message", NULL);
    PyObject_SetAttrString(pb2, "data", server.out_parameter->value);
    PyObject* serialized_pyobject = PyObject_CallMethod(pb2, "SerializeToString", NULL);

    if (serialized_pyobject == NULL) {
        if (PyErr_Occurred()) PyErr_Print();
        lf_print_error_and_exit("Could not serialize serialized_pyobject.");
    }
    Py_buffer serialized_message;
    int returnValue = PyBytes_AsStringAndSize(serialized_pyobject, &serialized_message.buf, &serialized_message.len);
    if (returnValue == -1) {
        if (PyErr_Occurred()) PyErr_Print();
        lf_print_error_and_exit("Could not serialize serialized_message.");
    }
    size_t message_length = serialized_message.len;
    send_timed_message(self->base.environment, 0, MSG_TYPE_TAGGED_MESSAGE, 0, 0, "federate 0 via the RTI", message_length, serialized_message.buf);
    Py_XDECREF(serialized_pyobject);
    /* Release the thread. No Python API allowed beyond this point. */
    PyGILState_Release(gstate);
}
#include "include/api/set_undef.h"
_federate__server_main_main_self_t* new__federate__server_main() {
    _federate__server_main_main_self_t* self = (_federate__server_main_main_self_t*)_lf_new_reactor(sizeof(_federate__server_main_main_self_t));
    #line 56 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    self->_lf_inputControlReactionTrigger._base.trigger = &self->_lf__inputControlReactionTrigger;
    #line 56 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    self->_lf_inputControlReactionTrigger.parent = (self_base_t*)self;
    #line 57 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    self->_lf_networkMessage._base.trigger = &self->_lf__networkMessage;
    #line 57 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    self->_lf_networkMessage.parent = (self_base_t*)self;
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_server_width = -2;
    #line 27 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 27 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    self->_lf_server.out_parameter_trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 27 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 27 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    self->_lf_server.out_parameter_reactions[0] = &self->_lf__reaction_2;
    #line 27 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    self->_lf_server.out_parameter_trigger.reactions = self->_lf_server.out_parameter_reactions;
    #line 27 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    self->_lf_server.out_parameter_trigger.last = NULL;
    #line 27 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    self->_lf_server.out_parameter_trigger.number_of_reactions = 1;
    #line 27 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    #ifdef FEDERATED
    #line 27 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    self->_lf_server.out_parameter_trigger.physical_time_of_arrival = NEVER;
    #line 27 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    #endif // FEDERATED
    #line 60 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    self->_lf__reaction_0.number = 0;
    #line 60 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    self->_lf__reaction_0.function = _federate__server_mainreaction_function_0;
    #line 60 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    self->_lf__reaction_0.self = self;
    #line 60 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    #line 60 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    self->_lf__reaction_0.STP_handler = NULL;
    #line 60 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    self->_lf__reaction_0.name = "?";
    #line 60 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    self->_lf__reaction_0.mode = NULL;
    #line 68 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    self->_lf__reaction_1.number = 1;
    #line 68 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    self->_lf__reaction_1.function = _federate__server_mainreaction_function_1;
    #line 68 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    self->_lf__reaction_1.self = self;
    #line 68 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    #line 68 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    self->_lf__reaction_1.STP_handler = NULL;
    #line 68 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    self->_lf__reaction_1.name = "?";
    #line 68 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    self->_lf__reaction_1.mode = NULL;
    #line 90 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    self->_lf__reaction_2.number = 2;
    #line 90 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    self->_lf__reaction_2.function = _federate__server_mainreaction_function_2;
    #line 90 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    self->_lf__reaction_2.self = self;
    #line 90 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    self->_lf__reaction_2.deadline_violation_handler = NULL;
    #line 90 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    self->_lf__reaction_2.STP_handler = NULL;
    #line 90 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    self->_lf__reaction_2.name = "?";
    #line 90 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    self->_lf__reaction_2.mode = NULL;
    #line 56 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    self->_lf__inputControlReactionTrigger.last = NULL;
    #line 56 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 56 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    self->_lf__inputControlReactionTrigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 56 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 56 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    #line 56 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    self->_lf__inputControlReactionTrigger_reactions[0] = &self->_lf__reaction_0;
    #line 56 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    self->_lf__inputControlReactionTrigger.reactions = &self->_lf__inputControlReactionTrigger_reactions[0];
    #line 56 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    self->_lf__inputControlReactionTrigger.number_of_reactions = 1;
    #line 56 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    #ifdef FEDERATED
    #line 56 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    self->_lf__inputControlReactionTrigger.physical_time_of_arrival = NEVER;
    #line 56 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    #endif // FEDERATED
    self->_lf__inputControlReactionTrigger.is_physical = false;
    
    self->_lf__inputControlReactionTrigger.tmplt.type.element_size = 0;
    self->_lf_inputControlReactionTrigger.type.element_size = 0;
    #line 57 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    self->_lf__networkMessage.last = NULL;
    #line 57 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 57 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    self->_lf__networkMessage.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 57 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 57 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    #line 57 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    self->_lf__networkMessage_reactions[0] = &self->_lf__reaction_1;
    #line 57 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    self->_lf__networkMessage.reactions = &self->_lf__networkMessage_reactions[0];
    #line 57 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    self->_lf__networkMessage.number_of_reactions = 1;
    #line 57 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    #ifdef FEDERATED
    #line 57 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    self->_lf__networkMessage.physical_time_of_arrival = NEVER;
    #line 57 "/mnt/c/Users/jacky/Desktop/simple_multi/fed-gen/Main/src/federate__server.lf"
    #endif // FEDERATED
    self->_lf__networkMessage.is_physical = false;
    
    self->_lf__networkMessage.tmplt.type.element_size = 0;
    self->_lf_networkMessage.type.element_size = 0;
    return self;
}
