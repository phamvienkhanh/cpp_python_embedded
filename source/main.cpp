
#include <fmt/core.h>
#include <fmt/color.h>

#include "backend.h"
#include "frontend.h"

int main(int argc, char *argv[])
{
    Resigter_backend();
    Py_Initialize();

    fmt::print("{} {} {}\n", __FILE__, __func__, __LINE__);
    bool rs = FrontEnd::AddModulePath("./python_test_source");
    fmt::print("{} {} {}\n", __FILE__, __func__, __LINE__);
    fmt::print("{} {} {}\n", __FILE__, __func__, __LINE__);
    FrontEnd frontEnd;
    frontEnd.loadModule("testfunc");

    fmt::print("{} {} {}\n", __FILE__, __func__, __LINE__);
    int rss = frontEnd.callFunc("onUpdate", 5, 6);
    fmt::print("{} {} {}\n", __FILE__, __func__, __LINE__);

    fmt::print("{} {} {}\n", __FILE__, __func__, __LINE__);
    if (Py_FinalizeEx() < 0) {
        fmt::print("{} {} {}\n", __FILE__, __func__, __LINE__);
        return 120;
    }

    fmt::print("{} {} {}\n", __FILE__, __func__, __LINE__);

    return 0;
}