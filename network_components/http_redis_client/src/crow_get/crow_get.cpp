#include <main_header.hpp>

void crow_key(crow::SimpleApp app, sw::redis::Redis& redis) {
    CROW_ROUTE(app, "/key/<string>").methods(crow::HTTPMethod::GET)
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
}

void crow_get(crow::SimpleApp app, sw::redis::Redis& redis) {
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
}

void crow_lpop(crow::SimpleApp app, sw::redis::Redis& redis) {
    CROW_ROUTE(app, "/lpop/<string>").methods(crow::HTTPMethod::GET)
    ([&redis](const std::string& key)
    {
        auto val = redis.lpop(key);
        if (val)
        {
            return crow::response(200, *val);
        }
        else
        {
            return crow::response(404, "Data not found");
        }
    });
}

void crow_rpop(crow::SimpleApp app, sw::redis::Redis& redis) {
    CROW_ROUTE(app, "/rpop/<string>").methods(crow::HTTPMethod::GET)
    ([&redis](const std::string& key)
    {
        auto val = redis.rpop(key);
        if (val)
        {
            return crow::response(200, *val);
        }
        else
        {
            return crow::response(404, "Data not found");
        }
    });
}

void crow_llen(crow::SimpleApp app, sw::redis::Redis& redis) {
    CROW_ROUTE(app, "/llen/<string>").methods(crow::HTTPMethod::GET)
    ([&redis](const std::string& key)
    {
        long long val = redis.llen(key);
        if (val)
        {
            std::string str = std::to_string(val);
            return crow::response(200, str);
        }
        else
        {
            return crow::response(404, "List is empty");
        }
    });
}


void crow_ping(crow::SimpleApp app, sw::redis::Redis& redis) {
    CROW_ROUTE(app, "/ping").methods(crow::HTTPMethod::GET)
    ([&redis]()
    {
        std::string val = redis.ping();
        if (!val.empty())
        {
            return crow::response(200, val);
        }
        else
        {
            return crow::response(404, "server unresponsive");
        }
    });
}

void crow_echo(crow::SimpleApp app, sw::redis::Redis& redis) {
    CROW_ROUTE(app, "/echo/<string>").methods(crow::HTTPMethod::GET)
    ([&redis](const std::string& msg)
    {
        std::string val = redis.echo(msg);
        if (!val.empty())
        {
            return crow::response(200, val);
        }
        else
        {
            return crow::response(404, "server unresponsive");
        }
    });
}

void crow_flushall(crow::SimpleApp app, sw::redis::Redis& redis) {
    CROW_ROUTE(app, "/flushall").methods(crow::HTTPMethod::GET)
    ([&redis]()
    {
        redis.flushall();
        return crow::response(200, "data has been flushed");
    });
}


void crow_info(crow::SimpleApp app, sw::redis::Redis& redis) {
    CROW_ROUTE(app, "/info").methods(crow::HTTPMethod::GET)
    ([&redis]()
    {
        std::string  val = redis.info();
        if (!val.empty())
        {
            return crow::response(200, val);
        }
        else
        {
            return crow::response(404, "Redis could not provide any info");
        }
    });
}

