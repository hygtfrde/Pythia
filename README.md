# Pythia
Test environment to support hygtfrde's delphi extractor project.

link to delphi: ``https://github.com/hygtfrde/delphi``


## How to install the environment;  

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