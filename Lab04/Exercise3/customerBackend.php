<?php
  $user = $_POST["email"];
  $pass = $_POST["password"];
  $tacos = $_POST["tacos"];
  $burritos = $_POST["burritos"];
  $enchiladas = $_POST["enchiladas"];
  $shipping = $_POST["shippingOption"];
  $total = 0;

  echo '<link rel="stylesheet" type="text/css" href="style.css"></head>';
  echo "<h1>Welcome " , $user, "!</h1>";
  echo "<h2 class='password'>Your password is: " , $pass, "</h2>";

  echo "<table id='receipt' class='receipt'>";
    echo "<tr>";
      echo "<th></th>";
      echo "<th>Quantity</th>";
      echo "<th>Cost Per Item</th>";
      echo "<th>Sub Total</th>";
    echo "</tr>";
    echo "<tr>";
      echo "<th>Tacos</th>";
      echo "<td>", $tacos, "</td>";
      echo "<td>$1.25</td>";
      echo "<td>$", (1.25*$tacos);
      if(1.25*$tacos*100%4 == 0){
        echo ".00";
      }
      $total = 1.25*$tacos;
      echo "</td>";
    echo "</tr>";
    echo "<tr>";
      echo "<th>Burritos</th>";
      echo "<td>", $burritos, "</td>";
      echo "<td>$3.50</td>";
      echo "<td>$", (3.50*$burritos);
      if($burritos == 0){
        echo ".00";
      }else{
        echo "0";
      }
      echo "</td>";
      $total = $total + 3.50*$burritos;
    echo "</tr>";
    echo "<tr>";
      echo "<th>Enchiladas</th>";
      echo "<td>", $enchiladas, "</td>";
      echo "<td>$5.00</td>";
      echo "<td>$", (5.00*$enchiladas), ".00</td>";
      $total = $total + 5.00*$enchiladas;
    echo "</tr>";
    echo "<tr>";
      echo "<th>Shipping</th>";
      echo "<td colspan='2'>", $shipping, "</td>";
      echo "<td>$";
      if($shipping == "Free 7 Days"){
        echo "0";
      }elseif($shipping == "3 Days"){
        echo "5";
        $total = $total + 5;
      }else{
        echo "50";
        $total = $total + 50;
      }
      echo ".00</td>";
    echo "</tr>";
    echo "<tr>";
      echo "<th = colspan='3'>Total Cost</th>";
      echo "<th>$", $total;
      if($total*100%4 == 0){
        echo ".00";
      }elseif($total*100%2 == 0){
        echo "0";
      }
      echo "</th>";
    echo "</tr>";
  echo "</table>";
?>
