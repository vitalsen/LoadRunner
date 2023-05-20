Action()
{
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
	cancelreservation();

	
	
	lr_think_time(5);
	logout();

	lr_end_transaction("2_script_delete_reservation", LR_AUTO);
	
	return 0;
}