#!/bin/bash

API_KEY=$(cat $HOME/.config/footy/api_key.txt)

# == PROCESS OPTIONS ==
usage() { echo "Usage: $0 [-s <league>] [-h]" 1>&2; exit 1; }
help_() { echo "Help menu" 1>&2; exit 0; }

while getopts ":s:h" opt; do
	case "${opt}" in
		s)
			# standings
			COMPETITION=${OPTARG}
			curl -sH "X-Auth-Token: $API_KEY" https://api.football-data.org/v2/competitions/$COMPETITION/standings | \
				jq -r '.standings[0].table[] | "\(.position),\(.team.name),\(.playedGames),\(.won),\(.draw),\(.lost),\(.points)"' | \
				column -ts "," -N Pos,Team,P,W,D,L,Pts -R Pos,P,W,D,L,Pts
			;;
		h)
			help_
			;;
		*)
			usage
			;;
	esac
done
