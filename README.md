# newyorkc [NYC]

## FAQ

### Max coins?
100 billion coins, just like DOGE.

### Coin type?
newyorkc is a Scrypt-based Proof of Work coin using the Komoto Gravity Well.

### Block Info

30 second Block Targets, KGW difficulty readjustment

Special reward system: Random block rewards


1-101: 	   1 newyorkc Reward

1-100,000: 0-1,000,000 newyorkc Reward

100,001 - 200,000: 0-500,000 newyorkc Reward

200,001 - 300,000: 0-250,000 newyorkc Reward

300,001 - 400,000: 0-125,000 newyorkc Reward

400,001 - 500,000: 0-62,500 newyorkc Reward

500,001 - 600,000: 0-31,250 newyorkc Reward

600,000+: 10,000 Reward (flat)

### Conf Settings

rpcuser=newyorkc

rpcpassword=nycoinpass

rpcport=18823

## Docker
[Instructions for installing docker](https://www.docker.com/community-edition).

First, build the image.
```
# go to the same directory Dockerfile exists
docker build .
```

You should see logs similar to below. This takes a while, as it is provisioning the image by installing dependencies and building the nycoin binary.
```
Sending build context to Docker daemon  156.4MB
Step 1/12 : FROM ubuntu:14.04
 ---> d6ed29ffda6b
 ..
 ..
 ..
 Preparing to unpack .../libboost-graph-parallel1.54.0_1.54.0-4ubuntu3.1_amd64.deb ...
 Unpacking libboost-graph-parallel1.54.0 (1.54.0-4ubuntu3.1) ...
 Selecting previously unselected package libicu52:amd64.
 Preparing to unpack .../libicu52_52.1-3ubuntu0.7_amd64.deb ...
 Unpacking libicu52:amd64 (52.1-3ubuntu0.7) ...
 Selecting previously unselected package libboost-regex1.54.0:amd64.
 Preparing to unpack .../libboost-regex1.54.0_1.54.0-4ubuntu3.1_amd64.deb ...
 ..
 ..
 ..
 ---> 062552e63b8c
Removing intermediate container 524ece488798
Successfully built 062552e63b8c
```

Then, copy the unique identifier built by Docker (in this case, `062552e63b8c`).
```
➜  nycoin git:(master) ✗ docker run -d 062552e63b8c
93f55a2fbc1082641fc8d99f9b3be182e46bd180f8e680fb69335d0b334fdf7a
```

This runs the binary, `newyorkcd`, with no command arguments.

`-d`: daemonize the container. Run `docker logs 93f55a2fbc -f` to tail the standard output.

`-v`: persist the data in your host machine. Example: `docker run -d -v $(pwd)/docker/data:/root/.newyorkc/ 062552e63b8c`
