#include <iostream>
#include <crow.h>
using namespace std;

int main()
{
    crow::SimpleApp app;

    // Route 1: Hello World
    CROW_ROUTE(app, "/")([](){
        return "Hello, World!";
    });

    // Route 3: Adding function (GET /add?a=1&b=2)
    CROW_ROUTE(app, "/add/<int>/<int>")
    ([](int a, int b){
        int sum = a + b;
        return crow::response(std::to_string(sum));
    });

    app.port(8080).multithreaded().run();
}