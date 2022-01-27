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
To get an overview of all supported leagues and teams, run `footy -l` and `footy -t`respectively.
Since the outputs will be very large, I recommend piping the output into a [pager](https://man7.org/linux/man-pages/man1/less.1.html) (e.g. `footy -l | less`), where you can then easily search for a specific league or team.
Anytime an option requires a league or team code (e.g. get standings in `footy -s <league-code>`), you can either use the `Code` or `Id` column from the tables provided by `footy -l` and `footy -r`.
Some leagues and teams do not have a unique `Code`, so you will have to use the `Id` there.

**Note**: Some of the (smaller) leagues require paid access ([pricing](https://www.football-data.org/coverage)). Therefore, the `Price` column shows which ones are free.

## Dependencies

[jq](https://stedolan.github.io/jq/): JSON processor  
[util-linux](https://github.com/util-linux/util-linux): for [column](https://man7.org/linux/man-pages/man1/column.1.html)

## License

The MIT License © Fritz Rehde
