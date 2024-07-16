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