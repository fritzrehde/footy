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
footy [-s <league>] [-k <api-key>] [-H] [-h]
```
Read about all the possible commands in the [USAGE](.USAGE.md) file.

## Dependencies

[jq](https://stedolan.github.io/jq/): JSON processor  
[util-linux](https://github.com/util-linux/util-linux): for [column](https://man7.org/linux/man-pages/man1/column.1.html)

## License

The MIT License © Fritz Rehde
