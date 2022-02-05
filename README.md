# footy

<i>A simple shell script that displays the latest football scores, fixtures and standings.</i>

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
**Note**: footy currently only supports Linux (due to some Linux-specific [dependencies](#dependencies)).

## Usage

```shell
footy [-s <league>] [-k <api-key>] [-l] [-t <league>] [-h]
```
Read about all the possible commands in the [USAGE](.USAGE.md) file.

### Supported leagues and teams
Use the `-l` option to get an overview of all supported leagues (I recommend piping the output into a [pager](https://man7.org/linux/man-pages/man1/less.1.html) (e.g. `footy -l | less`), then use `-t <league>` with either a league's `Code` or `Id` as the argument to see all teams in that league (e.g. `footy -t BL1` and `footy -t 2002` both work).

Some leagues and teams do not have a `Code`, so you will have to use the `Id` there.

**Note**: Access to some of the (smaller) leagues/teams is paid ([pricing](https://www.football-data.org/coverage)). Therefore, the `Price` column shows which leagues are free.

## Dependencies

[`jq`](https://stedolan.github.io/jq/): JSON processor  
[`util-linux`](https://github.com/util-linux/util-linux): for [`column`](https://man7.org/linux/man-pages/man1/column.1.html)

## License

The MIT License © Fritz Rehde
