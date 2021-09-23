# Introduction to the Development Environment

This lab is in a Jupyter notebook (`Lab.ipynb`).  To run it'll you'll need to 

1.  Get access to Docker (either through campus or on your own machine)
2.  Check out the lab.

This document describe how to do those two things.  Then, you'll be able to
open the Jupyter notebook and proceed with lab itself.

# Software You Will Need

1. A computer with Docker installed (either the cloud docker container via ssh, or your own laptop).  If you are using you're own machine, you'll need at least 8GB of free memory.
2. The lab for the github classroom assignment for this lab.  Find the link on the course home page: https://github.com/CSE141pp/Home/.

## Get Docker Working

All your work for the class will be done in a docker container.  Docker
containers are self-contained Linux-based workspaces.  Using docker ensures
that your code runs in a consistent environment for you and the
autograder/course staff.

There are two options for getting getting access to docker.

1.  Use the campus servers (which is the supported method).

2.  Run docker on your own machine (which is not supported, but there there is
    [some documentation](RunningDocker.md)).

### Get on the VPN

To use the campus servers, you'll also need to be on the [campus
VPN](https://blink.ucsd.edu/technology/network/connections/off-campus/VPN/).  

I know it's not great.  We have tried to find a way around it and there is nothing we can do.

### Use dsmlp-login.ucsd.edu

This is the official way to use the class infrastructure.  If you have trouble
getting any of the other options to work, use this.

Login to `dsmlp-login.ucsd.edu` (our primary student Linux SSH server) using you normal student login.

Run the command `launch-142` to connect to a remote Docker container running the development environment image.

Here's a transcript of the login process for user `sjswanson`:

```
Kilgores-MacBook-Pro-1323:~/UCSD/Teaching-dev/cse142/tng/CSE141pp-Root ssh sjswanson@dsmlp-login.ucsd.edu
Last login: Thu Aug 19 10:25:14 2021 from cpe-24-94-6-245.san.res.rr.com

quota: No filesystem specified.
Hello sjswanson, you are currently logged into dsmlp-login.ucsd.edu

You are using 0% CPU on this system


*** Potential downtime/disruption of services ***

August 22, 2021, 7:00am-7:30am

Work on backend file servers may disrupt login sessions or software launched from /software or /acsnfs3/software.




[sjswanson@dsmlp-login]:~:499$ launch-142
Attempting to create job ('pod') with 1 CPU cores, 2 GB RAM, and 0 GPU units.
   (Adjust command line options, or edit "/datasets/home/89/589/sjswanson/my-launch-142" to change this configuration.)
pod/sjswanson-23790 created
Thu Aug 19 10:32:41 PDT 2021 starting up - pod status: Pending ; Successfully assigned sjswanson/sjswanson-23790 to its-dsmlp-n19.ucsd.edu
Thu Aug 19 10:32:46 PDT 2021 pod is running with IP: 10.40.0.4 on node: its-dsmlp-n19.ucsd.edu
stevenjswanson/cse142l-runner:v15 is now active.

Please connect to: http://dsmlp-login.ucsd.edu:1989/?token=80fb1310d723d124880cc21035afed53d675d7b776aef57d0ebed2c80b33d8

Connected to sjswanson-23790; type 'exit' to terminate pod/processes and close Jupyter notebooks.
sjswanson@sjswanson-23790:~$
```

To make sure everything is working, you can run `cse142 --help`.  You should get something like this:

```
Usage: cse142 [OPTIONS] COMMAND [ARGS]...

Options:
  --server URL        Base url for the HTTP interface to the cluster.
  --http / --no-http  Use HTTP or connect directly
  -v, --verbose       Be Verbose
  -d, --debug         Enable debugging
  --json              Output results in json
  --trace             Drop into the debugger immediately
  --pdb               Invoke the debugger on uncaught exception.
  -n, --dry-run       Don't do anything, just say what would be done.
  --job-type TEXT     class name of job type to use
  --help              Show this message and exit.

Commands:
  cluster
  dev      Run a docker image configured for use with cse142L.
  job
  lab
  login
  logout
  user
```

If you go this route, you can skip instructions below regarding running
`docker` directly.

You can then clone your repo in the directory that you land in and work on it.

Your files inside the `launch-142` environment are stored in this system:
https://datahub.ucsd.edu/hub/login.

## Cloning the Lab Repo

First, accept the assignement on Github Classroom.  It's available via the 142L
[home page](https://github.com/CSE141pp/Home/).

This will set you up with a copy of the starter repository.

Get yourself into docker as described above, and `git clone` the repo locally.

You may need to create an ssh key on dsmlp and add it to your github account.  You can create the key with:

```
ssh-keygen
```

Then view your new public key:

```
cat ~/.ssh/id_rsa.pub
```

Then follow these instructions:

https://docs.github.com/en/github/authenticating-to-github/connecting-to-github-with-ssh/adding-a-new-ssh-key-to-your-github-account


## Opening Jupyter Notebook

If you are running on DSMLP, there is a url that appears early in the login
that will tell you where to connect.  In the example above, it's this line:

```
Please connect to: http://dsmlp-login.ucsd.edu:1989/?token=80fb1310d723d124880cc21035afed53d675d7b776aef57d0ebed2c80b33d8
```

If it has scrolled away you can get it back with 

```
echo $LAUNCH_PROXY_URL
```

Copy and paste that url into a browser or click on it and then navigate to the directory where you cloned out the lab.

If you get

```
This site can’t be reached
dsmlp-login.ucsd.edu refused to connect.
```

That's because you aren't on the VPN.  It seems that you need to log all the way out of dslmp and back in after you connected to the VPN.
 
## Log in to the Course Tools

Navigate to the director you just cloned.  Click on `Login.ipynb` in the lab repo you just cloned and follow the instructions.  This will log you into the course tools.

## Open the Notebook

Click on `Lab.ipynb` to open the lab and get to work!

