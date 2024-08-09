#include <main_header.hpp>

int main(void)
{
    sw::redis::Redis redis("tcp://pythiaOnRedis:6379");
    while (true)
    { 
        if (redis.llen(key) > 0 )
        {
            auto val = redis.lpop(key);
            Pythia::run_tests();
        }
    }
    
    return EXIT_SUCCESS;
}