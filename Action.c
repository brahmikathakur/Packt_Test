Action()
{
	//Enclosing each user action between a start/end transaction for better understanding of the results
	
	lr_start_transaction("Blazedemo_HomePage");
	
	web_url("Blazedemo_HomePage", 
		"URL=https://blazedemo.com/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/favicon.ico", ENDITEM, 
		LAST);
	
	lr_end_transaction("Blazedemo_HomePage", LR_AUTO);

	//Adding "think time" between different transaction for simulation real user experience
	
	lr_think_time(1);
	
	//Applied "content check" on the page response for validation
	
	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=BlazeDemo - reserve",
		LAST);
	
	lr_start_transaction("Find_Flight");
	
	web_submit_data("Find_Flight", 
		"Action=https://blazedemo.com/reserve.php", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://blazedemo.com/", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=fromPort", "Value={FromPort}", ENDITEM,	//Parameterizing the static values
		"Name=toPort", "Value={ToPort}", ENDITEM, 
		LAST);

	lr_end_transaction("Find_Flight", LR_AUTO);
	
	
	lr_think_time(1);
	

	return 0;
}