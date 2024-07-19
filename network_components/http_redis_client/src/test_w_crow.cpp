#include <main_header.hpp>

int test_w_crow()
{
    sw::redis::Redis redis("tcp://pythiaOnRedis:6379");
    crow::SimpleApp app;

    //post
    crow_set(app, redis);
    crow_lpush(app, redis);
    crow_rpush(app, redis);

    // get
    crow_key(app, redis);
    crow_get(app, redis);
    crow_lpop(app, redis);
    crow_rpop(app, redis);
    crow_llen(app, redis);
    crow_ping(app, redis);
    // void crow_echo(app, redis);
    // crow_flushall(app, redis);
    crow_info(app, redis);


    app.port(18080).multithreaded().run();
    return EXIT_SUCCESS;
}