<?php
require __DIR__ . '/vendor/autoload.php';
use Kreait\Firebase\Factory;
use Kreait\Firebase\ServiceAccount;
use Kreait\Firebase;

$serviceAccount = ServiceAccount::fromJsonFile(__DIR__ . '/google-service-account.json');

$firebase = (new Factory)
    ->withServiceAccount($serviceAccount)
    ->create();

$database = $firebase->getDatabase();
$fullArray = $database->getReference('001')->getValue();
echo json_encode($fullArray, JSON_PRETTY_PRINT);
