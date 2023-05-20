opensite(){
lr_start_transaction("open_site");
web_reg_find("Text/IC=<title>Web Tours</title>",
		LAST);

	web_reg_save_param("userSession",
		"LB/IC=name=\"userSession\" value=\"",
		"RB=\"/>",
		LAST);
	
	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("open_site", LR_AUTO);
};
login(){
lr_start_transaction("login");

	web_revert_auto_header("Sec-Fetch-User");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_header("Origin", 
		"http://localhost:1080");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");
	
	web_reg_find("Text/IC=User password was correct",
		LAST);
web_reg_find("Text=Welcome, <b>{username}</b>, to the Web Tours",LAST);

	web_submit_data("login.pl", 
		"Action=http://localhost:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=body", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value={userSession}", ENDITEM, 
		"Name=username", "Value={username}", ENDITEM, 
		"Name=password", "Value={password}", ENDITEM, 
		"Name=login.x", "Value=67", ENDITEM, 
		"Name=login.y", "Value=10", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		LAST);

	lr_end_transaction("login",LR_AUTO);
};
gotoflight(){
lr_start_transaction("go_to_flights");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	web_reg_find("Text=User has returned to the search page.",
		LAST);
web_reg_find("Text=<b>Find Flight<",LAST);


	web_url("Search Flights Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=search", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("go_to_flights",LR_AUTO);
};

check_tiket(){lr_start_transaction("Check_ticket");
	
	web_reg_save_param("flightID",
	"LB=flightID\" value=\"",
	"RB=\"",
	LAST);
	                   
	

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_reg_find("Text=User wants the intineraries",
		LAST);

	web_url("Itinerary Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Check_ticket", LR_AUTO);};
logout(){lr_start_transaction("log_out");

	web_revert_auto_header("Origin");

	web_reg_find("Text/IC=A Session ID has been created",
		LAST);

	web_url("SignOff Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);

lr_end_transaction("log_out",LR_AUTO);
};
findflight(){lr_start_transaction("fing_flight");
	
/*Correlation comment - Do not change!  Original value='192;271;05/1/2023' Name ='outboundFlight' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=outboundFlight",
		"TagName=input",
		"Extract=value",
		"Name=outboundFlight",
		"Type=radio",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		LAST);
	web_add_auto_header("Origin", 
		"http://localhost:1080");

	web_reg_find("Text=Flight departing from ",
		LAST);
		
		web_reg_find("Text=from <B>{DepartureCity}</B> to <B>{ArrivalCity}</B> on <B>{departDate}</B>",
		LAST);
	 web_reg_find("Text=from <B>{ArrivalCity}</B> to <B>{DepartureCity}</B> on <B>{returnDate}</B>",
		LAST);
		web_reg_save_param("outboundFlight",
		"LB/IC=name=\"outboundFlight\" value=\"",
		"RB/IC=\"",
		"Ord=ALL",
		LAST);

	
	web_reg_save_param("returnFlight",
		"LB/IC=\"returnFlight\" value=\"",
		"RB/IC=\"",
		"Ord=ALL",
		LAST);
		
		


	



	web_submit_data("reservations.pl", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=depart", "Value={DepartureCity}", ENDITEM, 
		"Name=departDate", "Value={departDate}", ENDITEM, 
		"Name=arrive", "Value={ArrivalCity}", ENDITEM, 
		"Name=returnDate", "Value={returnDate}", ENDITEM, 
		"Name=numPassengers", "Value={countPass}", ENDITEM,
		"Name=roundtrip", "Value={roundtrip}", ENDITEM,
		"Name=seatPref", "Value={seating_preference}", ENDITEM, 
		"Name=seatType", "Value={type_of_seat}", ENDITEM, 
		"Name=findFlights.x", "Value=55", ENDITEM, 
		"Name=findFlights.y", "Value=11", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		LAST);
		lr_save_string(lr_paramarr_random("outboundFlight"), "randomFlight");
		

	lr_end_transaction("fing_flight",LR_AUTO);};
cancelreservation(){lr_start_transaction("Cancel_reservation");
	
	web_reg_find("Fail=Found",
	"Text={flightID}",
	LAST);
	

	web_add_header("Origin", 
		"http://localhost:1080");

	web_add_header("Sec-Fetch-Dest", 
		"frame");

	web_add_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_reg_find("Text=Flights List",
		LAST);

	web_submit_form("itinerary.pl", 
    "Snapshot=t100.inf", 
    ITEMDATA, 
    "Name=1", "Value=on", ENDITEM,  
    "Name=removeFlights.x", "Value=72", ENDITEM, 
    "Name=removeFlights.y", "Value=1", ENDITEM, 
    LAST);

	lr_end_transaction("Cancel_reservation",LR_AUTO);};
selectticket(){lr_start_transaction("select_ticket");
	
	web_reg_find("Text=Street Address",
		LAST);

	web_submit_data("reservations.pl_2",
		"Action=http://localhost:1080/cgi-bin/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/reservations.pl",
		"Snapshot=t12.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=outboundFlight", "Value={outboundFlight}", ENDITEM,
		"Name=numPassengers", "Value=1", ENDITEM,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=seatType", "Value=First", ENDITEM,
		"Name=seatPref", "Value=Window", ENDITEM,
		"Name=reserveFlights.x", "Value=48", ENDITEM,
		"Name=reserveFlights.y", "Value=13", ENDITEM,
		LAST);

	lr_end_transaction("select_ticket",LR_AUTO);};
paymentdetails(){lr_start_transaction("payment_details");

	web_revert_auto_header("Origin");

	web_revert_auto_header("Sec-Fetch-User");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_header("Origin", 
		"http://localhost:1080");

	web_reg_find("Text=Reservation Made!",
		LAST);

	web_submit_data("reservations.pl_3",
		"Action=http://localhost:1080/cgi-bin/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/reservations.pl",
		"Snapshot=t13.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=firstName", "Value={FirstName}", ENDITEM,
		"Name=lastName", "Value={LastName}", ENDITEM,
		"Name=address1", "Value={adress}", ENDITEM,
		"Name=address2", "Value={adress2}", ENDITEM,
		"Name=pass1", "Value= {FirstName} {LastName}", ENDITEM,
		"Name=pass2", "Value={FirstName2} {LastName2} ", ENDITEM,
		"Name=pass3", "Value= {FirstName3}{LastName3}",ENDITEM,
		"Name=creditCard", "Value={creditcard}", ENDITEM,
		"Name=expDate", "Value={exp_date}" , ENDITEM,
		"Name=oldCCOption", "Value=", ENDITEM,
		"Name=numPassengers", "Value={countPass}", ENDITEM,
		"Name=seatType", "Value={type_of_seat}", ENDITEM,
		"Name=seatPref", "Value={seating_preference}", ENDITEM,
		"Name=outboundFlight", "Value={randomFlight} ", ENDITEM,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=returnFlight", "Value=", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		"Name=buyFlights.x", "Value=62", ENDITEM,
		"Name=buyFlights.y", "Value=11", ENDITEM,
		"Name=.cgifields", "Value=saveCC", ENDITEM,
		LAST);

	lr_end_transaction("payment_details",LR_AUTO);};




























