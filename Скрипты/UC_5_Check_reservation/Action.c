Action()
{
	lr_start_transaction("5_Skript_Check_reservation");

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

	
	web_set_sockets_option("SSL_VERSION", "2&3");
	
	
	lr_think_time(5);

	login();

	
	
	
	
	
	lr_think_time(5);
	gotoflight();
	lr_think_time(5);
	
	check_tiket();


	
	
	
	
	
	
	
	
lr_think_time(5);
logout();


	lr_end_transaction("5_Skript_Check_reservation", LR_AUTO);

	return 0;
}