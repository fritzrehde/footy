#!/bin/bash

API_KEY=$(cat $HOME/.config/footy/api_key.txt)

# Set script name and full path
FOOTY_SH=$(basename "$0")
FOOTY_FULL_SH="$0"
# export TODO_SH TODO_FULL_SH

# == HELP MESSAGES ==
USAGE="$0 [-s <league>] [-h]"

usage()
{
	cat <<-EOF >&2
	Usage: $USAGE
	Try '$FOOTY_SH -h' for more information.
	EOF
	exit 1
}

shorthelp()
{
	cat <<-EOF
	Usage: $USAGE
	-s <league>   Prints the standings in specified league.
	-k <api-key>  Saves the api-key for www.football-data.org in $HOME/.config/footy/api_key.txt
	-H            Prints names of all supported leagues or teams.
	-h            Prints this user documentation.
	EOF
	exit 0
}

longhelp()
{
	cat <<-EOF
	Usage: $USAGE
	long help
	EOF
	exit 0
}

# == PROCESS OPTIONS ==
while getopts ":s:hH" opt; do
	case "${opt}" in
		h)
			shorthelp
			;;
		H)
			longhelp
			;;
		k)
			;;
		s)
			# standings
			COMPETITION=${OPTARG}
			curl -sH "X-Auth-Token: $API_KEY" https://api.football-data.org/v2/competitions/$COMPETITION/standings | \
				jq -r '.standings[0].table[] | "\(.position),\(.team.name),\(.playedGames),\(.won),\(.draw),\(.lost),\(.points)"' | \
				column -ts "," -N Pos,Team,P,W,D,L,Pts -R Pos,P,W,D,L,Pts
			;;
		*)
			usage
			;;
	esac
done
