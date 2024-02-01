/*

******************************************************************************************************************

RevolutionX Libraries
Founded December 2012, Releasd on Github 2024
Lib Release 0.0.0.1, RC-1

Main Library:
				- rxtracking.inc (provides a easy and free way to track your players (thanks to IPINFODB)

[!] MAIN LIBRARY SUMMARY
This library is designed to let you track player accounts! Get an IPINFODB API key or this will not work

FUNCTIONS LIST:

	- GetPlayerCountry
	- GetPlayerST
	- GetPlayerCit
	- GetPlayerLatitude
	- GetPlayerLongitude



************************************************************************************************************************

*/

#include <a_samp>
#include <a_http>
new r_pass[35];

#define IPAPI_KEY "b4d0"


stock GetPlayerCountry(playerid)
{
	new str[100];
	new ip[26];
	GetPlayerIp(playerid,ip,sizeof ip);
	format(str,sizeof str,"api.ipinfodb.com/v3/ip-city/?key=%s&ip=%s",IPAPI_KEY,ip);
	HTTP(playerid,HTTP_GET,str,"","IPInfoDB_Connect1");
	return r_pass;
}

stock GetPlayerST(playerid)
{
	new str[100];
	new ip[26];
	GetPlayerIp(playerid,ip,sizeof ip);
	format(str,sizeof str,"api.ipinfodb.com/v3/ip-city/?key=%s&ip=%s",IPAPI_KEY,ip);
	HTTP(playerid,HTTP_GET,str,"","IPInfoDB_Connect2");
	return r_pass;
}

stock GetPlayerCity(playerid)
{
	new str[100];
	new ip[26];
	GetPlayerIp(playerid,ip,sizeof ip);
	format(str,sizeof str,"api.ipinfodb.com/v3/ip-city/?key=%s&ip=%s",IPAPI_KEY,ip);
	HTTP(playerid,HTTP_GET,str,"","IPInfoDB_Connect3");
	return r_pass;
}

stock GetPlayerLatitude(playerid)
{
	new str[100];
	new ip[26];
	GetPlayerIp(playerid,ip,sizeof ip);
	format(str,sizeof str,"api.ipinfodb.com/v3/ip-city/?key=%s&ip=%s",IPAPI_KEY,ip);
	HTTP(playerid,HTTP_GET,str,"","IPInfoDB_Connect4");
	return r_pass;
}

stock GetPlayerLongitude(playerid)
{
	new str[100];
	new ip[26];
	GetPlayerIp(playerid,ip,sizeof ip);
	format(str,sizeof str,"api.ipinfodb.com/v3/ip-city/?key=%s&ip=%s",IPAPI_KEY,ip);
	HTTP(playerid,HTTP_GET,str,"","IPInfoDB_Connect5");
	return r_pass;
}

forward IPInfoDB_Admin(index, response_code, data[]);
public IPInfoDB_Admin(index, response_code, data[])
{
    if(response_code == 200)
    {
		strdel(data,0,4);
		new data2[9][60];
		split(data,data2, ';');
		new str[150];
		format(str,sizeof str,"Country: %s (%s) - City: %s (GMT %s)\n",data2[2],data2[1],data2[4],data2[8]);
		//SendClientMessage(index,COLOR_GREY,str);
		format(str,sizeof str,"%sState: %s - Zip: %s\n",str,data2[3],data2[5]);
		//SendClientMessage(index,COLOR_GREY,str);
		format(str,sizeof str,"%sLatitude: %s - Longitude: %s",str,data2[6],data2[7]);
		//SendClientMessage(index,COLOR_GREY,str);
		PlayerPlaySound(index,1057,0.0,0.0,0.0);

  		ShowPlayerDialog(index,33,DIALOG_STYLE_MSGBOX,"Tracking Results:",str,"Ok","");
    }   else ShowPlayerDialog(index,33,DIALOG_STYLE_MSGBOX,"Tracking Results:","Error Connecting to Tracking Service.\nTry again.","Ok","");
}

forward IPInfoDB_Connect1(index, response_code, data[]);
public IPInfoDB_Connect1(index, response_code, data[])
{
	strdel(data,0,4);
	new data2[9][60];
	split(data,data2, ';');
	new name[20];
	GetPlayerName(index,name,sizeof name);
    if(response_code == 200)
    {
		format(r_pass,sizeof r_pass,"%s",data2[2]);
	}
}

forward IPInfoDB_Connect2(index, response_code, data[]);
public IPInfoDB_Connect2(index, response_code, data[])
{
	strdel(data,0,4);
	new data2[9][60];
	split(data,data2, ';');
	new name[20];
	GetPlayerName(index,name,sizeof name);
    if(response_code == 200)
    {
		format(r_pass,sizeof r_pass,"%s",data2[3]);
	}
}

forward IPInfoDB_Connect3(index, response_code, data[]);
public IPInfoDB_Connect3(index, response_code, data[])
{
	strdel(data,0,4);
	new data2[9][60];
	split(data,data2, ';');
	new name[20];
	GetPlayerName(index,name,sizeof name);
    if(response_code == 200)
    {
		format(r_pass,sizeof r_pass,"%s",data2[4]);
	}
}

forward IPInfoDB_Connect4(index, response_code, data[]);
public IPInfoDB_Connect4(index, response_code, data[])
{
	strdel(data,0,4);
	new data2[9][60];
	split(data,data2, ';');
	new name[20];
	GetPlayerName(index,name,sizeof name);
    if(response_code == 200)
    {
		format(r_pass,sizeof r_pass,"%s",data2[6]);
	}
}

forward IPInfoDB_Connect5(index, response_code, data[]);
public IPInfoDB_Connect5(index, response_code, data[])
{
	strdel(data,0,4);
	new data2[9][60];
	split(data,data2, ';');
	new name[20];
	GetPlayerName(index,name,sizeof name);
    if(response_code == 200)
    {
		format(r_pass,sizeof r_pass,"%s",data2[7]);
	}
}

split(const strsrc[], strdest[][], delimiter)
{
	new i, li;
	new aNum;
	new len;
	while(i <= strlen(strsrc)){
	    if(strsrc[i]==delimiter || i==strlen(strsrc)){
	        len = strmid(strdest[aNum], strsrc, li, i, 128);
	        strdest[aNum][len] = 0;
	        li = i+1;
	        aNum++;
		}
		i++;
	}
	return 1;
}
