#include <main_header.hpp>
#include <unordered_map>

void crow_set(crow::SimpleApp app, sw::redis::Redis& redis)
{
    CROW_ROUTE(app, "/set").methods(crow::HTTPMethod::POST)
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
}

void crow_lpush(crow::SimpleApp app, sw::redis::Redis& redis)
{
    CROW_ROUTE(app, "/lpush").methods(crow::HTTPMethod::POST)
    ([&redis](const crow::request& req)
    {
        auto x = crow::json::load(req.body);
        if (!x)
        {
            return crow::response(400, "Invalid JSON");
        }

        std::string key = x["key"].s();
        std::string value = x["value"].s();

        redis.lpush(key, value);

        return crow::response(200, "Data stored successfully");
    });
}

void crow_rpush(crow::SimpleApp app, sw::redis::Redis& redis)
{
    CROW_ROUTE(app, "/rpush").methods(crow::HTTPMethod::POST)
    ([&redis](const crow::request& req)
    {
        auto x = crow::json::load(req.body);
        if (!x)
        {
            return crow::response(400, "Invalid JSON");
        }

        std::string key = x["key"].s();
        std::string value = x["value"].s();

        redis.rpush(key, value);

        return crow::response(200, "Data stored successfully");
    });
}

void crow_hmset(crow::SimpleApp app, sw::redis::Redis& redis)
{
    CROW_ROUTE(app, "/hmset").methods(crow::HTTPMethod::POST)
    ([&redis](const crow::request& req)
    {
        auto x = crow::json::load(req.body);
        if (!x)
        {
            return crow::response(400, "Invalid JSON");
        }

        std::string hash = x["key"].s();
        std::unordered_map<std::string, std::string> fields_values;

        const auto& fields = x["fields_values"];
        for (auto it = fields.begin(); it != fields.end(); ++it)
        {
            fields_values[it->key()] = it->s();
        }

        redis.hmset(hash, fields_values.begin(), fields_values.end());

        return crow::response(200, "Hash data stored successfully");
    });
}