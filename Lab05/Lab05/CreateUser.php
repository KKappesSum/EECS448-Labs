<?php
    $userName = $_POST[userName];
    $mysqli = new mysqli("mysql.eecs.ku.edu", "kylekappessum", "aiMoh4yu", "kylekappessum");
    $query = 0;

    if($mysqli->connect_errno){
        echo "<h2>Bad Connection to SQL</h2>";
        exit();
    }

    $query = "INSERT into Users (user_id) values ('$userName')";


    if($userName == "" || $userName == "\0"){
        echo "<h2>Could not create user: Invalid username</h2>";
    }elseif($mysqli->query($query) === true){
        echo "<h2>Created User ";
        echo $userName;
        echo "</h2>";
    }else {
        echo "<h2>Could not create user: User already exists</h2>";
    }
?>
