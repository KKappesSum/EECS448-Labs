<?php
    $username = $_POST["username"];
    $mysqli = new mysqli("mysql.eecs.ku.edu", "kylekappessum", "aiMoh4yu", "kylekappessum");
    $query = 0;

    if($mysqli->connect_errno){
        echo "<h2>Bad Connection to SQL</h2>";
        exit();
    }

    $query = "SELECT * from Users";
    $count = 0;
    $result = $mysqli->query($query);
    while($cur = $result->fetch_assoc()){
            if($username == $cur["user_id"]){
                break;
            }else{
                $count++;
            }
    }

    $query= "SELECT * from Posts where author_id='$count'";
    echo "<table>";
    echo "<tr>";
    echo "<th>$username's Posts:</th>";
    echo "</tr>";
    $result = $mysqli->query($query);
    while($cur = $result->fetch_assoc()){
        echo "<tr><td>";
        echo $cur["content"];
        echo "</td></tr>";
    }
    echo "</table>";
?>
