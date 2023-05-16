/* godot-cpp integration testing project.
 *
 * This is free and unencumbered software released into the public domain.
 */

#include "hello.h"

#include <godot_cpp/core/class_db.hpp>

#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/label.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

Hello::Hello() {
	id = 0;
	UtilityFunctions::print("hello id ", itos(id));
}

Hello::~Hello() {
	id = 1;
	UtilityFunctions::print("hello id ", itos(id));
}

void Hello::_bind_methods() {
	// Methods.
	ClassDB::bind_method(D_METHOD("say_hi"), &Hello::_say_hi);
	ClassDB::bind_method(D_METHOD("simple_func"), &Hello::simple_func);
	ClassDB::bind_method(D_METHOD("simple_const_func"), &Hello::simple_const_func);
	ClassDB::bind_method(D_METHOD("return_something"), &Hello::return_something);
}

// Methods.
void Hello::_say_hi(const String &name) {
	UtilityFunctions::print("hello ", name);
}

void Hello::simple_func() {
	UtilityFunctions::print("  Simple func called.");
}

void Hello::simple_const_func() const {
	UtilityFunctions::print("  Simple const func called.");
}

String Hello::return_something(const String &base) {
	UtilityFunctions::print("  Return something called.");
	return base;
}
