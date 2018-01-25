![New York Coin](https://i.imgur.com/4xxIr9Y.jpg)

# newyorkc [NYC]

## This repo is an NYC community driven effort to update the existing NYC codebase and wallets.

A lot has happened in the crypto space since 2014 and the NewYorkCoin community has grown dramatically.
Security and ease of use are paramount concerns, the community is actively discussing and organizing to address those concerns.

For more information visit the NewYorkCoin community [Discord group](https://discord.gg/Rty2ZZV)

=======

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
