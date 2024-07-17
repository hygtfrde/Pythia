#include <main_header.hpp>

int test_w_crow()
{
    sw::redis::Redis redis("tcp://pythiaOnRedis:6379");
    crow::SimpleApp app;
    CROW_ROUTE(app, "/get/<string>").methods(crow::HTTPMethod::GET)
    ([&redis](const std::string& key)
    {
        auto val = redis.get(key);
        if (val)
        {
            return crow::response(200, *val);
        }
        else
        {
            return crow::response(404, "Data not found");
        }
    });

    CROW_ROUTE(app, "/post").methods(crow::HTTPMethod::POST)
    ([&redis](const crow::request& req)
    {
        auto x = crow::json::load(req.body);
        if (!x)
        {
            return crow::response(400, "Invalid JSON");
        }

        std::string key = x["key"].s();
        std::string value = x["value"].s();

        redis.set(key, value);

        return crow::response(200, "Data stored successfully");
    });
    app.port(18080).multithreaded().run();
    return EXIT_SUCCESS;
}