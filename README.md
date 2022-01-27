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
make
```
Set the api-key by running `footy -k <api-key>` or manually create the file `$HOME/.config/footy/api-key.txt` containing only the api-key.  

**Note**: footy currently only supports Linux (due to some Linux-specific [dependencies](#dependencies)).

## Usage

```shell
footy [-s <league>] [-k <api-key>] [-l] [-t] [-h]
```
Read about all the possible commands in the [USAGE](.USAGE.md) file.

### Supported leagues and teams
To get an overview of all supported leagues and teams, use the `-l` and `-t` options.
I recommend piping the output into a [pager](https://man7.org/linux/man-pages/man1/less.1.html) (e.g. `footy -l | less`), so you can easily search for a specific league or team.  

Generally, the `Code` and `Id` columns can both be used in options (e.g. `footy -s BL1` and `footy -s 2002` both work).
However, some leagues and teams do not have a `Code`, so you will have to use the `Id` there.

**Note**: Some of the (smaller) leagues require paid access ([pricing](https://www.football-data.org/coverage)). Therefore, the `Price` column shows which leagues are free.

## Dependencies

[jq](https://stedolan.github.io/jq/): JSON processor  
[util-linux](https://github.com/util-linux/util-linux): for [column](https://man7.org/linux/man-pages/man1/column.1.html)

## License

The MIT License © Fritz Rehde
