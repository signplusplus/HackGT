<?php
//instantiate Twilio API
//get data from JSON sent from iOS side
//parse phone number(s) out
//use API to take the text and make a phone call and leave a voice message 


require 'twilio-php/Services/Twilio.php'; //include the PHP twilio library


//test code taken from Twilio site to test functionality 

// set your AccountSid and AuthToken from www.twilio.com/user/account
$AccountSid = "AC0aa13285c8c301f6172130472b7db9db";
$AuthToken = "de1302ea440ce5a09818738b15fc60a2";
 
$client = new Services_Twilio($AccountSid, $AuthToken);
 
$message = $client->account->messages->create(array(
    "From" => "706-604-8049",
    "To" => "706-604-8049",
    "Body" => "Test message!",
));
 
// Display a confirmation message on the screen
echo "Sent message {$message->sid}";

?>