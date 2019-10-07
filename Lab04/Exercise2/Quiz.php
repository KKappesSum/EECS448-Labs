<?php
$q1 = $_POST["question1"];
$q2 = $_POST["question2"];
$q3 = $_POST["question3"];
$q4 = $_POST["question4"];
$q5 = $_POST["question5"];
$count = 0;

  echo "<p>Question 1: The wild turkey is the only bird with a ______.</p>";
  echo "<p>You answered: " , $q1 , "</p>";
  echo "<p>Correct answer: Beard</p><br>";

  echo "<p>Question 2: Americans did not commonly use ______ until after the Civil War.</p>";
  echo "<p>You answered: " , $q2 , "</p>";
  echo "<p>Correct answer: Forks</p><br>";

  echo "<p>Question 3: Every hour one ______ cells in the human body must be replaced.</p>";
  echo "<p>You answered: " , $q3 , "</p>";
  echo "<p>Correct answer: 1 Billion</p><br>";

  echo "<p>Question 4: A mole can dig upto ______ feet in one night.</p>";
  echo "<p>You answered: " , $q4 , "</p>";
  echo "<p>Correct answer: 300</p><br>";

  echo "<p>Question 5: Hypnotism was banned by public schools in ______.</p>";
  echo "<p>You answered: " , $q5 , "</p>";
  echo "<p>Correct answer: San Diego</p><br>";

  if($q1 == "Beard"){
    $count++;
  }
  if($q2 == "Forks"){
    $count++;
  }
  if($q3 == "1 Billion"){
    $count++;
  }
  if($q4 == "300"){
    $count++;
  }
  if($q5 == "San Diego"){
    $count++;
  }
  echo "<p>You got ", $count , " questions correct out of 5.</p>";
  echo "<p>You Scored: ", 100*($count/5.0) ,"%</p>";
?>
