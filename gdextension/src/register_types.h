/* godot-cpp integration testing project.
 *
 * This is free and unencumbered software released into the public domain.
 */

#ifndef HELLO_REGISTER_TYPES_H
#define HELLO_REGISTER_TYPES_H

#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void initialize_hello_module(ModuleInitializationLevel p_level);
void uninitialize_hello_module(ModuleInitializationLevel p_level);

#endif // HELLO_REGISTER_TYPES_H
