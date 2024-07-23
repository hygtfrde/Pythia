#ifndef __MY_API_H_
#define __MY_API_H_

#include <main_header.hpp>

//post
void crow_set(crow::SimpleApp app, sw::redis::Redis& redis);
void crow_lpush(crow::SimpleApp app, sw::redis::Redis& redis);
void crow_rpush(crow::SimpleApp app, sw::redis::Redis& redis);
void crow_hmget(crow::SimpleApp app, sw::redis::Redis& redis);

// get
void crow_key(crow::SimpleApp app, sw::redis::Redis& redis);
void crow_get(crow::SimpleApp app, sw::redis::Redis& redis);
void crow_lpop(crow::SimpleApp app, sw::redis::Redis& redis);
void crow_rpop(crow::SimpleApp app, sw::redis::Redis& redis);
void crow_llen(crow::SimpleApp app, sw::redis::Redis& redis);
void crow_hmset(crow::SimpleApp app, sw::redis::Redis& redis);
void crow_ping(crow::SimpleApp app, sw::redis::Redis& redis);
void crow_echo(crow::SimpleApp app, sw::redis::Redis& redis);
void crow_flushall(crow::SimpleApp app, sw::redis::Redis& redis);
void crow_info(crow::SimpleApp app, sw::redis::Redis& redis);

#endif