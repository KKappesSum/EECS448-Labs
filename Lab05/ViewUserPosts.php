<?php
    $username = $_POST["username"];
    $mysqli = new mysqli("mysql.eecs.ku.edu", "kylekappessum", "aiMoh4yu", "kylekappessum");
    $query = 0;

    if($mysqli->connect_errno){
        echo "<h2>Bad Connection to SQL</h2>";
        exit();
    }

    $query= "SELECT * from Posts where author_id='$username'";
    echo "<table border='1 solid black'>";
    echo "<tr>";
    echo "<th>$username's Posts:</th>";
    echo "</tr>";
    $result = $mysqli->query($query);
    while($cur = $result->fetch_assoc()){
        echo "<tr><td border='1 solid black'>";
        echo $cur["content"];
        echo "</td></tr>";
    }
    echo "</table>";
?>
