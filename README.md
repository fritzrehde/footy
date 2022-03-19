# footy

<i>A simple shell script that displays the latest football scores, fixtures and standings.</i>

<img src="https://raw.githubusercontent.com/fritzrehde/i/master/footy/footy-preview.png" width=600>

## Table of Contents

- [Features](#features)
- [Install](#install)
	- [Build from source](#build-from-source)
	- [Linux](#linux)
	- [MacOS](#macos)
- [Usage](#usage)
	- [Supported leagues and teams](#supported-leagues-and-teams)
	- [Piping output to other tools](#piping-output-to-other-tools)
- [Dependencies](#dependencies)
- [License](#license)

## Features

- **Minimalistic output**: aiming to adhere to the [Unix philosophy](https://en.wikipedia.org/wiki/Unix_philosophy), footy's output can easily be piped to other tools
- **Portable**: minimal [dependencies](#dependencies)

## Install

Since footy uses the data provided by [football-data.org](https://www.football-data.org/), an api-key is required.
You can register for one [here](https://www.football-data.org/client/register) for free.

Once footy is installed, set the api-key by running `footy -k <api-key>` or manually create the file `$HOME/.config/footy/api-key.txt` containing only the api-key.  

### Build from source
```shell
git clone https://github.com/fritzrehde/footy.git
cd footy
sudo make install
```

**Note:** The makefile defaults to some default paths for installed files. Adjust to your system:

- `INSTALL_DIR`: PATH for executables (default /usr/local/bin)

```shell
make install INSTALL_DIR=/usr/bin
```

### Linux
AUR (Arch User Repository): *to be added*

### MacOS
Homebrew: *to be added*


## Usage
```text
OPTIONS:
  -s            Prints standings/table
                Must be used with -l <league>
  -m <+/-days>  Prints upcoming ('+' prefix) or previous ('-' prefix) matches 
                Must be used with either -l <league> or -t <team>
  -l <league>   Specifies league (use league's code or id)
  -t <team>     Specifies team (must use team's id)
  -I            Prints all supported leagues
  -i <league>   Prints all teams in league (use league's code or id)
  -r            Unformatted output for piping to other tools
  -k <api-key>  Saves the api-key to $HOME/.config/footy/api-key.txt
  -h            Prints this help message
```

### Supported leagues and teams
`footy -I` gives you an overview of all the supported leagues (I recommend piping the output into a [pager](https://man7.org/linux/man-pages/man1/less.1.html)).

`footy -i BL1` or `footy -i 2002` prints all teams in the Bundesliga using either the *Code* `BL1` or the *Id* `2002`.

Some leagues and teams do not have a *Code*, so you will have to use the *Id* there.

**Note**: Access to some of the smaller leagues/teams is paid ([pricing](https://www.football-data.org/coverage)). Therefore, the *Price* column shows which leagues are free.

### Piping output to other tools

The `-r` option provides unformatted output, where the columns are seperated by commas instead of whitespaces and the match dates are in the ISO-8601 UTC format.

#### Example
```
footy -s BL1 -r | cut -d ',' -f 1-6,10 | column -ts ','
```
This command will only display the first six and the tenth column of the standings output.

## Dependencies

- [`jq`](https://stedolan.github.io/jq/): JSON processor

## License

The MIT License © Fritz Rehde
