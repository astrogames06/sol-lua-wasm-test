extern "C" {
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}

#include <iostream>

int main() {
    lua_State* L = luaL_newstate();      // Create new Lua state
    luaL_openlibs(L);                    // Open standard Lua libraries

    // Run a Lua script string
    if (luaL_dostring(L, "print('Hello, World from Lua in WASM!')")) {
        // If error occurs
        std::cerr << "Lua error: " << lua_tostring(L, -1) << std::endl;
        lua_pop(L, 1);
    }

    lua_close(L); // Close Lua state
    return 0;
}
