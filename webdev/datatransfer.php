<?php
//instantiate Twilio API
//get data from JSON sent from iOS side
//parse phone number(s) out
//use API to take the text and make a phone call and leave a voice message 

ini_set('display_errors', 1);
error_reporting(E_ALL ^ E_NOTICE);

require ('twilio-php/Services/Twilio.php'); //include the PHP twilio library

// Twilio REST API version
$version = "2010-04-01";
     
$account_sid = 'AC0aa13285c8c301f6172130472b7db9db'; 
$auth_token = 'de1302ea440ce5a09818738b15fc60a2'; 
// A phone number you have previously validated with Twilio
$phonenumber = '+17062252340';
     
// Instantiate a new Twilio Rest Client
$client = new Services_Twilio($account_sid, $auth_token, $version);
 
try {
    // Initiate a new outbound call
    $call = $client->account->calls->create(
    $phonenumber, // The number of the phone initiating the call
    '7066048049', // The number of the phone receiving call
    'http://demo.twilio.com/welcome/voice/' // The URL Twilio will request when the call is answered
    );
    
    echo 'Started call: ' . $call->sid;
    } catch (Exception $e) {
        echo 'Error: ' . $e->getMessage();
    }

echo "Loaded page";
echo "<br>";



?>