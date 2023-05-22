Action()
{
	int flight_id_num = 0;
	lr_start_transaction("2_script_delete_reservation");

	web_set_sockets_option("SSL_VERSION", "2&3");

	web_add_auto_header("Sec-Fetch-Site", 
		"none");

	web_add_auto_header("Sec-Fetch-Dest", 
		"document");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");
	
	opensite();

	
	lr_think_time(5);
	
	login();
	lr_think_time(5);
	
	

	check_tiket();
	
	lr_think_time(5);
	lr_start_transaction("Cancel_reservation");

			web_add_header("Origin", 
				"http://localhost:1080");
			
			web_reg_find("Fail=NotFound",
				"Text=Flight Transaction Summary",
				LAST);	
				
			web_reg_save_param("flights_numbers",
				"LB=<b>A total of ",
				"RB= scheduled flights.</font></b>",
				LAST);

			if (atoi(lr_eval_string("{delete_num}")) == 1){
				
				web_submit_form("web_submit_form",
					ITEMDATA,
					"Name=1", "Value=on", ENDITEM,
					"Name=removeFlights.x", "Value=33", ENDITEM,
					"Name=removeFlights.y", "Value=4", ENDITEM,
					EXTRARES,
					"URL=http://localhost:1080/cgi-bin/itinerary.pl",
					"Referer=http://localhost:1080/cgi-bin/itinerary.pl", ENDITEM,
					LAST);
			
			} else if (atoi(lr_eval_string("{delete_num}")) == 2){
				
				web_submit_form("web_submit_form",
					ITEMDATA,
					"Name=1", "Value=on", ENDITEM,
					"Name=2", "Value=on", ENDITEM,
					"Name=removeFlights.x", "Value=33", ENDITEM,
					"Name=removeFlights.y", "Value=4", ENDITEM,
					EXTRARES,
					"URL=http://localhost:1080/cgi-bin/itinerary.pl",
					"Referer=http://localhost:1080/cgi-bin/itinerary.pl", ENDITEM,
					LAST);
			
			} else if (atoi(lr_eval_string("{delete_num}")) == 3){
				
				web_submit_form("web_submit_form",
					ITEMDATA,
					"Name=1", "Value=on", ENDITEM,
					"Name=2", "Value=on", ENDITEM,
					"Name=3", "Value=on", ENDITEM,
					"Name=removeFlights.x", "Value=33", ENDITEM,
					"Name=removeFlights.y", "Value=4", ENDITEM,
					EXTRARES,
					"URL=http://localhost:1080/cgi-bin/itinerary.pl",
					"Referer=http://localhost:1080/cgi-bin/itinerary.pl", ENDITEM,
					LAST);
			
			}
		     
			if(atoi(lr_eval_string("{flights_numbers}")) >= flight_id_num)
				{
			    	lr_error_message("Itinerary not deleted");
				} 
			else if (atoi(lr_eval_string("{flights_numbers}")) < flight_id_num) 
				{
			        lr_output_message("Itinerary deleted succuess");
			    }

		lr_end_transaction("Cancel_reservation", LR_AUTO);

	
	
	lr_think_time(5);
	logout();

	lr_end_transaction("2_script_delete_reservation", LR_AUTO);
	
	return 0;
}