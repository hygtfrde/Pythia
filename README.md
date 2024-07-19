# Pythia
Test environment to support hygtfrde's delphi extractor project.

link to delphi: ``https://github.com/hygtfrde/delphi``


## How to install the environment.

### Step 1. setup the Environment.
Using docker.

- Create a docker network:
```bash
docker network create pythiaNetwork
```

- Pull redis image: 
```bash
docker pull redis
```

```bash
docker run --name pythiaOnRedis --network pythiaNetwork -d redis
```

### Step 2. Build the nginx load balancer.

From the ``network_components/nginx_load_balancer`` dir:

- Build the nginx image:
```bash
docker build -t my-nginx-load-balancer .
```

- Run the nginx container:
```bash
docker run --name nginx-lb --net pythiaNetwork -p 80:80 my-nginx-load-balancer
```

### Step 3. Build the redis client.


From the ``network_components/http_redis_client`` dir.
- Build the image:
```bash
docker build -t img_llvm_redispp_crow .
```

- Then run the container:
```bash
docker run -it --network pythiaNetwork -v .:/workspace --name cont_llvm_redispp_crow img_llvm_redispp_crow /bin/bash
```


From the ``network_components/http_redis_client/build`` dir.

- Run Cmake to generate makefile:
``` bash
cmake ..
```

- Run make to compile:
```bash
make
```

- Run the redis client:
```bash
./pythia
```

- Remove current build:
```bash
make clean
```

From the project root dir.
- Remove ``build`` dir before generating a new makefile:
```bash
rm -r build
mkdir build
```


### https/server crow documentation.

https://crowcpp.org/master/guides/routes/

We are using nginx so the connection needs to be non SSL


#### Hot to use with with curl and crow  

let's make some post and get request to our server via the load balancer !

(Don't forget to use the appropriate port)

If you have issues, try to add ``-X POST `` or ``-X GET`` in front of ``curl``, but it should ne be necessary. 

| Category | Redis    | Arguments     | Usage           |
| -------- | -------- | ------------- | --------------- |
| POST     | set      | set           | curl http://localhost:80/set \ <br> -H "Content-Type: application/json" \ <br> -d '{"key":"mykey", "value":"myvalue"}'|
| POST     | lpush    | lpush         | curl http://localhost:80/lpush \ <br> -H "Content-Type: application/json" \ <br> -d '{"key":"mykey", "value":"myvalue"}'|
| POST     | rpush    | rpush         | curl http://localhost:80/lpush \ <br> -H "Content-Type: application/json" \ <br> -d '{"key":"mykey", "value":"myvalue"}'|
| GET      | key      | key/<string>  | curl http://localhost:80/key/key_value|
| GET      | get      | key/<string>  | curl http://localhost:80/get/key_value|
| GET      | lpop     | lpop/<string> | curl http://localhost:80/lpop/key_value|
| GET      | lpop     | rpop/<string> | curl http://localhost:80/rpop/key_value|
| GET      | llen     | llen/<string> | curl http://localhost:80/llen/key_value|
| GET      | llen     | ping          | curl http://localhost:80/ping|
| GET      | echo     | echo/<string> | curl http://localhost:80/echo/msg|
| GET      | flushall | flushall      | curl http://localhost:80/echo/msg|
| GET      | info     | info          | curl http://localhost:80/info|









post request :

```sh
curl http://localhost:80/post \
    -H "Content-Type: application/json" \
    -d '{"key":"mykey", "value":"myvalue"}'
```

get request:
```sh
curl http://localhost:80/get/mykey
```


### redis-plus-plus documentation

https://github.com/sewenew/redis-plus-plus/blob/master/src/sw/redis%2B%2B/redis.h

### googleTest documentation
https://google.github.io/googletest/
https://github.com/google/googletest/tree/main/googletest/samples



