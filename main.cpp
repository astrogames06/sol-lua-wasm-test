#include <sol/sol.hpp>
#include <emscripten/emscripten.h>
#include <emscripten/bind.h>
#include <iostream>

sol::state lua;

void run_lua(const std::string& code)
{
    sol::protected_function_result result = lua.safe_script(code, &sol::script_pass_on_error);
    
    if (!result.valid())
    {
        sol::error err = result;
        std::cout << "Lua error caught: " << err.what() << std::endl;
    }
}
EMSCRIPTEN_BINDINGS(module_bindings)
{
    emscripten::function("RunLua", &run_lua);
}

int main() {
	std::cout << "=== opening a state ===" << std::endl;

	// open some common libraries
	lua.open_libraries(sol::lib::base, sol::lib::package);
	lua.script("print('bark bark bark!')");

    return 0;
}
