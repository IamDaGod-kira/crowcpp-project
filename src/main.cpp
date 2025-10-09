#include <iostream>
#include <crow.h>
using namespace std;

int main()
{
    crow::SimpleApp app;

    crow::mustache::set_global_base("./templates");

    // Route 1: Hello World
    CROW_ROUTE(app, "/")([](){
        return "Hello, World!";
    });

    // Router 2: templates/index.html
    CROW_ROUTE(app, "/main")([](){
        auto page = crow::mustache::load("index.html");
        return page.render();
    });

    // Route 3: Adding function (GET /add?a=1&b=2)
    CROW_ROUTE(app, "/add/<int>/<int>")([](int a, int b){
        int sum = a + b;
        return crow::response(to_string(sum));
    });

    CROW_ROUTE(app, "/name/<string>")([](string name){
        string hello = "Hello " + name;
        return crow::response(hello);
    });

    app.port(8080).multithreaded().run();
}