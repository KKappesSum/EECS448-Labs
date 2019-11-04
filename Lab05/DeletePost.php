<?php
    $posts = $_POST[posts];
    $mysqli = new mysqli("mysql.eecs.ku.edu", "kylekappessum", "aiMoh4yu", "kylekappessum");
    $query = 0;

    if($mysqli->connect_errno){
        echo "<h2>Bad Connection to SQL</h2>";
        exit();
    }

    if(empty($posts)){
        echo "<h2>No posts were selected for deletion.</h2>";
    }else{
        $max = count($posts);
        echo "<table border='1 solid black'><tr>";
        echo "<th border='1 solid black'>Deleted Post IDs</th>";
        for($i = 0; $i < $max; $i++){
            $query = "DELETE from Posts where post_id='$posts[$i]'";
            $mysqli->query($query);

            echo "</tr><tr><td>";
            echo "$posts[$i]";
            echo "</td>";
        }
        echo "</tr></table>";
    }

?>
