<?php class Employee {

	public function __construct($newName = "Unknown Name", $newWage = 7.25, $newKids = 0) {
		$this->setName($newName);
		$this->setWage($newWage);
		$this->setKids($newKids);
	}
	
	public function __toString() {
		return $this->name;
		// 	   "Wage: " . $this->wage . "<br/>" .
		// 	   "Kids: " . $this->kids . "<br/>";
	}

	public function getName() { return $this->name; }
	public function getWage() { return $this->wage; }
	public function getKids() { return $this->kids; }	

	public function setName($newName = "Unknown Name") {

		//Error Handling
		if (!is_string($newName)) { $this->name = "Unknown Name"; return false; }
		
		//Good Case
		$this->name = $newName;	
		return true;
	}

	public function setWage($newWage = 7.25) {

		//Error Handling
		if (!is_numeric($newWage)) { $this->wage = 7.25; return false; }
		if ($newWage < 7.25) { $this->wage = 7.25; return false; }

		//Good Case
		$this->wage = $newWage;
		return true;
	}
	
	public function setKids($newKids = 0) {

		//Error Case
		if (!is_numeric($newKids)) { $this->kids = 0; return false; }
		if ($newKids < 0) { $this->kids = 0; return false; }
		if ($newKids > 9) { $this->kids = 9; return false; }

		//Good Case
		$this->kids = $newKids;
		return true;
	}

	public function computePay($hours = 0) {

		//Calculate Gross Pay
		$grossPay = $hours * $this->wage;
		if ($hours > 40) {
			$hours -= 40;
			$grossPay += $hours * 0.5 * $this->wage;
		}


		$ssDeduction = $grossPay * 0.062;
		$mcDeduction = $grossPay * 0.0145;
		$witholdBase = $grossPay - (75 * $this->kids);

		if ($witholdBase <=  160) { return ($grossPay - $ssDeduction - $mcDeduction - (   0.00)); }
		if ($witholdBase <=  503) { return ($grossPay - $ssDeduction - $mcDeduction - (   0.00	+ 0.10 * ($witholdBase -  160))); }
		if ($witholdBase <= 1554) { return ($grossPay - $ssDeduction - $mcDeduction - (  34.30 	+ 0.15 * ($witholdBase -  503))); }
		if ($witholdBase <= 2975) { return ($grossPay - $ssDeduction - $mcDeduction - ( 191.95 	+ 0.25 * ($witholdBase - 1554))); }
		if ($witholdBase <= 4449) { return ($grossPay - $ssDeduction - $mcDeduction - ( 547.20 	+ 0.28 * ($witholdBase - 2975))); }
		if ($witholdBase <= 7820) { return ($grossPay - $ssDeduction - $mcDeduction - ( 959.92 	+ 0.33 * ($witholdBase - 4449))); }
		if ($witholdBase <= 8813) { return ($grossPay - $ssDeduction - $mcDeduction - (2072.35 	+ 0.35 * ($witholdBase - 7820))); }
									return ($grossPay - $ssDeduction - $mcDeduction - (2419.90 	+ .396 * ($witholdBase - 8813)));

	}

	private $name;
	private $wage;
	private $kids;

} ?>
