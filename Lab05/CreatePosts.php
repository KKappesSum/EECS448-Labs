<?php
    $userName = $_POST["userName"];
    $posttext = $_POST["postText"];
    $mysqli = new mysqli("mysql.eecs.ku.edu", "kylekappessum", "aiMoh4yu", "kylekappessum");
    $query = 0;
    $invalid = "<h2>Could not find user: Invalid username</h2>";
    $isvalid = false;

    if($mysqli->connect_errno){
        echo "<h2>Bad Connection to SQL</h2>";
        exit();
    }

    $query= "SELECT user_id from Users";

    if($userName == "" || $userName == "\0"){
        $invalid = "<h2>Could not find user: No username given</h2>";
    }elseif($posttext == "" || $posttext == "\0" || $posttext== " " || $posttext == "\t" || $posttext == "\n"){
        $invalid = "<h2>No post content or invalid post content</h2>";
    }else{
        $result = $mysqli->query($query);
        while($cur = $result->fetch_assoc()){
            if($userName == $cur["user_id"]){
                $isvalid = true;
                break;
            }
        }
    }

    if($isvalid){
        $query = "SELECT * from Posts";
        $count = 1;
        $result = $mysqli->query($query);
        while($cur = $result->fetch_assoc()){
                $count++;
        }

        $query = "SELECT * from Users";
        $count1 = 0;
        $result = $mysqli->query($query);
        while($cur = $result->fetch_assoc()){
                if($userName == $cur["user_id"]){
                    break;
                }else{
                    $count1++;
                }
        }

        $query = "INSERT into Posts (post_id, content, author_id) values ('$count', '$posttext', '$count1')";
        if($mysqli->query($query)){
            echo "Post created";
        }else{
            echo "Post failed";
        }
    }else{
        echo $invalid;
    }
?>
