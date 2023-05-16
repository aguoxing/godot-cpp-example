/* godot-cpp integration testing project.
 *
 * This is free and unencumbered software released into the public domain.
 */

#ifndef HELLO_CLASS_H
#define HELLO_CLASS_H

// We don't need windows.h in this example plugin but many others do, and it can
// lead to annoying situations due to the ton of macros it defines.
// So we include it and make sure CI warns us if we use something that conflicts
// with a Windows define.
#ifdef WIN32
#include <windows.h>
#endif

#include <godot_cpp/classes/control.hpp>
#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/viewport.hpp>

#include <godot_cpp/core/binder_common.hpp>

using namespace godot;

class Hello : public Control {
	GDCLASS(Hello, Control)

private:
	int id;

protected:
	static void _bind_methods();
	void _say_hi(const String &name);

public:
  Hello();
	~Hello();

	// Functions.
	void simple_func();
	void simple_const_func() const;
	String return_something(const String &base);

};

#endif //  HELLO_CLASS_H