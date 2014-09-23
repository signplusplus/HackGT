<?php
//get json file
//parse out phone numbers
//take string data
//send as voice message to phone numbers
	
require ('twilio-php/Services/Twilio.php'); //include the PHP twilio library

//echo "simple";
//echo $_SERVER['PATH_INFO'];
	
$version = "2010-04-01";

$file = "textToSpeech.xml";

$xml = simplexml_load_file($file);


$textMessage = $_POST["message"];


$sendNumber = $_POST["number"];

$arr = array('The Number' => $sendNumber);

echo json_encode($arr);

     
$account_sid = 'AC0aa13285c8c301f6172130472b7db9db'; 
$auth_token = 'de1302ea440ce5a09818738b15fc60a2'; 

// A phone number you have previously validated with Twilio
$phonenumber = '+14046206865';
$client = new Services_Twilio($account_sid, $auth_token, $version);
 
 
// $xml->Response->Dial = $sendNumber;
 $xml->Response->Say = $textMessage; 
 
 file_put_contents($file, $xml->asXML());
 
 
try {
    // Initiate a new outbound call
   $client->account->calls->create(
    $phonenumber, // The number of the phone initiating the call
   $sendNumber,
   // The number of the phone receiving call
   // '9089677453',
  // "testingSpeech.xml" 
  'http://demo.twilio.com/welcome/voice/'
    // The URL Twilio will request when the call is answered
    );
        
        
//echo 'Started call: ' . $call->sid;
} catch (Exception $e) {
        
   //echo 'Error: ' . $e->getMessage();
}
?>

