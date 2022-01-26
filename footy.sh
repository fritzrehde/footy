#!/bin/bash

API_KEY=$(cat $HOME/.config/footy/api_key.txt)

# standings
COMP=$1
curl -sH "X-Auth-Token: $API_KEY" https://api.football-data.org/v2/competitions/$COMP/standings | \
	jq -r '.standings[0].table[] | "\(.position),\(.team.name),\(.won),\(.draw),\(.lost),\(.points)"' | \
	column -ts "," -N Pos,Team,W,D,L,Pts -R Pos,W,D,L,Pts
