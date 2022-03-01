# footy

<i>A simple shell script that displays the latest football scores, fixtures and standings.</i>

## Features

- **Minimalistic output**: footy's output can easily be piped to other commands (like `awk`) for uses in shell scripts
- **Portable**: minimal [dependencies](#dependencies)

## Install

Since footy uses the data provided by [football-data.org](https://www.football-data.org/), an api-key is required.
You can register for one [here](https://www.football-data.org/client/register) for free.

### Linux

#### Build from source
```shell
git clone https://github.com/fritzrehde/footy.git
cd footy
sudo make install
```
Set the api-key by running `footy -k <api-key>` or manually create the file `$HOME/.config/footy/api-key.txt` containing only the api-key.  

**Note:** Makefile defaults to some default paths for installed files. Adjust to your system:

- `INSTALL_DIR`: PATH for executables (default /usr/local/bin)

```shell
make install INSTALL_DIR=/usr/bin
```

## Usage
```text
Usage: footy [-s <league> | -l | -t <league> | -k <api-key> | -h]
-s <league>         Prints standings in a league (use league's code or id).
-l                  Prints all supported leagues.
-t <league>         Prints all teams in a league (use league's code or id).
-k <api-key>        Saves the api-key to $HOME/.config/footy/api-key.txt
-h                  Prints this user documentation.
```
<!-- Read about all the possible commands in the [USAGE](.USAGE.md) file. -->

### Supported leagues and teams
Use the `-l` option to get an overview of all supported leagues (I recommend piping the output into a [pager](https://man7.org/linux/man-pages/man1/less.1.html) (e.g. `footy -l | less`)), then use `-t <league>` with either a league's *Code* or *Id* as the argument to see all teams in that league (e.g. `footy -t BL1` and `footy -t 2002` both work).

Some leagues and teams do not have a *Code*, so you will have to use the *Id* there.

**Note**: Access to some of the (smaller) leagues/teams is paid ([pricing](https://www.football-data.org/coverage)). Therefore, the *Price* column shows which leagues are free.

## Dependencies

- [`jq`](https://stedolan.github.io/jq/): JSON processor  

## License

The MIT License © Fritz Rehde
