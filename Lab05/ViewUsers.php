<?php
    $mysqli = new mysqli("mysql.eecs.ku.edu", "kylekappessum", "aiMoh4yu", "kylekappessum");
    $query = 0;

    if($mysqli->connect_errno){
        echo "<h2>Bad Connection to SQL</h2>";
        exit();
    }

    $query= "SELECT * from Users";
    echo "<table border='1 solid black'>";
    echo "<tr>";
    echo "<th>Users</th>";
    echo "</tr>";
    $result = $mysqli->query($query);
    while($cur = $result->fetch_assoc()){
        echo "<tr><td border='1 solid black'>";
        echo $cur["user_id"];
        echo "</td></tr>";
    }
    echo "</table>";
?>
