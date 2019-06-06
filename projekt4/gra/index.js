

document.getElementById("box").style.backgroundColor="blue";



let state="X";

let size={x:6,y:7};
let array=[];
let sequence=4;
let moves = 0

const reloadBoard = function () {

	console.log(".")
	size.x = parseInt(document.getElementById("xSize").value)
	size.y = parseInt(document.getElementById("ySize").value)
	sequence = parseInt(document.getElementById("seq").value)

	console.log("board reloaded: ", size, sequence)

	make_board()
}

const make_board=function(){
	
	
	var range = document.createRange();
	range.selectNodeContents(document.getElementById("box"));
	range.deleteContents();

	array = []
	moves = 0


	for(let i=0; i<size.y; ++i){
		let row=document.createElement("div");
		row.className="row";
		let array_2=[];

		for(let j=0; j<size.x; ++j){
			let new_rt=document.createElement("div");
			new_rt.innerHTML=".";
			new_rt.className="rectangle";
			new_rt.classList.add("sign_buff");
			new_rt.setAttribute("x",j);
			new_rt.setAttribute("y",i);
			//new_rt.style.margin="0px";
			row.appendChild(new_rt);
			array_2.push(".");
		}
		document.getElementById("box").appendChild(row);
		array.push(array_2);
	}
	//console.log(array);


	let list=document.getElementsByClassName("rectangle");
	for(let item of list){
		item.addEventListener("click", ()=>{

			//console.log(state);

			if(item.innerHTML=="X" || item.innerHTML=="O") return;
			let text=document.createTextNode(state);
			item.innerHTML="";
			item.classList.remove("sign_buff");
			item.appendChild(text);
			item.classList.add(item.innerHTML=="X" ? "sign_X": "sign_Y");
			
			let x=item.getAttribute("x");
			x=parseInt(x);
			let y=item.getAttribute("y");
			y=parseInt(y);
			//console.log(x+y);
			array[y][x]=state;

			if(state=="X") state="O";
			else state="X";

			setTimeout(()=>{
				let winner = check_winner()
				moves ++
				if(winner != null){
					console.log("Wygrana "+winner)					
					winNotification(winner)
					return 
				}

				if(moves == size.x*size.y){
					console.log("Remis")
					winNotification(null)
					return	
				}

				
				playAI('X', 'O')
				winner = check_winner()
				moves++
				
				if(winner != null){
					console.log("Wygrana "+winner)
					winNotification(winner)
					return 
				}

				if(moves == size.x*size.y){
					console.log("Remis")
					winNotification(null)
					return	
				}


			}, 200);
		});
	}
}

const winNotification = function(winner){
	setTimeout(() => {
		var range = document.createRange();
		range.selectNodeContents(document.getElementById("box"));
		range.deleteContents();
		let t = document.createElement("template")
		
		if(winner==null){
			t.innerHTML = `<div><h1 class="winNotification">Remis</h1><span>Odśwież aby zagrać ponownie</span></div>`
		}
		else{
			t.innerHTML = `<div><h1 class="winNotification">Wygrana ${winner}</h1><span>Odśwież aby zagrać ponownie</span></div>`
		}

		let children = t.content.childNodes

		children.forEach((e) => {
			document.getElementById("box").appendChild(e)
		})
	},1000)
}

const check_winner=function(){

	//alert("dziala");
	let buff=0;

	for(let i=0; i<array.length; ++i){
		for(let j=0; j<array[i].length; ++j){
			
			console.log(i+sequence, array.length);
			if(array[i][j]==".") continue;

			for(let a=j+1; a<j+sequence && j+sequence<=array[i].length; ++a){
			//	console.log(i,j,array[i][a]);
				if(array[i][j]==array[i][a]){
					buff=1;
				}
				else {
					buff=0;
					break;
				}

			}
			if(buff==1){
				return array[i][j];
			}
			
//////////////////////////////////////////////////////////////////////////////
			for(let b=i+1; b<i+sequence && i+sequence<=array.length; ++b){
			//.	alert("dziala");
				//console.log(i,j,array[b][j]);
				if(array[i][j]==array[b][j]){
					buff=1;
				}
				else {
					buff=0;
					break;
				}

			}
			if(buff==1){
				return array[i][j];
			}

//////////////////////////////////////////////////////////////////////////////
		
			for(let c=1; c<sequence && j+sequence<=array[i].length && i+sequence<=array.length; ++c){
				//console.log(i,j,array[i+c][j+c]);
				if(array[i][j]==array[i+c][j+c]){
					buff=1;
				}
				else{
					buff=0;
					break;
				}
			}
			if(buff==1){
				return array[i][j];
			}

///////////////////////////////////////////////////////////////////////////////

			for(let d=1; d<sequence && j+sequence<=array[i].length && i-sequence+1>=0; ++d){
				console.log(i,j,array[i-d][j+d]);
				if(array[i][j]==array[i-d][j+d]){
					buff=1;
				}
				else{
					buff=0;
				}
			}			
			if(buff==1){
				return array[i][j];
			}
		}

	}

	//console.log(array)
	return null;
}


const playAIRandom = function(){
	
	while(true){
		let x = Math.floor((Math.random() * size.x));
		let y = Math.floor((Math.random() * size.y));

		
		if(array[y][x] != ".") continue

		array[y][x] = state	

		let list=document.getElementsByClassName("rectangle");
		
		for(let item of list){
			if(item.getAttribute("x") == x && item.getAttribute("y") == y){
				let text=document.createTextNode(state);
				item.innerHTML="";
				item.classList.remove("sign_buff");
				item.appendChild(text);
				item.classList.add(item.innerHTML=="X" ? "sign_X": "sign_Y");
			}
		}

		console.log("CHANGED:", x,y);

		if(state=="X") state="O";
		else state="X";
		
		return
	}
}

const AIMakeTurn = function(x,y){
	if(array[y][x] != ".") return false

	array[y][x] = state	

	let list=document.getElementsByClassName("rectangle");
	
	for(let item of list){
		if(item.getAttribute("x") == x && item.getAttribute("y") == y){
			let text=document.createTextNode(state);
			item.innerHTML="";
			item.classList.remove("sign_buff");
			item.appendChild(text);
			item.classList.add(item.innerHTML=="X" ? "sign_X": "sign_Y");
		}
	}

	if(state=="X") state="O";
	else state="X";

	return true
}

const playAI = function(player, oponent){
	
	let oponentFields = createArray(size.x, size.y) //pola dobre dla gracza (do obrony)
	let playerFields = createArray(size.x, size.y) //pola dobre dla komputera (do ataku)
	//console.log(filds);
	
	for(let i=0;i<size.y;++i){
		for(let j=0;j<size.x;++j){

			if(array[i][j] != ".") continue 
			
			let i93 = iterate9_3(array, j, i, sequence)
			let i126 = iterate12_6(array, j, i, sequence)
			let i72 = iterate7_2(array, j, i, sequence)
			let i115 = iterate11_5(array, j, i, sequence)

			let sumOfOponent = bidirectionalSequence(i93, player, oponent) +
						 bidirectionalSequence(i126, player, oponent) +
						 bidirectionalSequence(i72, player, oponent) +
						 bidirectionalSequence(i115, player, oponent) 

			let sumOfPlayer = bidirectionalSequence(i93, oponent, player)+
						 bidirectionalSequence(i126, oponent, player)+ 
						 bidirectionalSequence(i72, oponent, player)+ 
						 bidirectionalSequence(i115, oponent, player)  

			oponentFields[i][j] = sumOfOponent
			playerFields[i][j] = sumOfPlayer 

		}
	}

	oponentFields = multiply2D(oponentFields, 1)
	playerFields = multiply2D(playerFields, 1)

	//let goodFields = treshold2D(oponentFields, 0.8)
	let goodFields = sum2D(oponentFields, playerFields)
	let chosen = max2D(goodFields)
	AIMakeTurn(chosen.x, chosen.y)
	console.log("oponent's filds\n", oponentFields);
	console.log("oponent's treshold\n", goodFields);
	console.log("player's filds\n", playerFields);
	console.log("player's decision\n", chosen);
}

//we wszystkich funckjach iterate liczby odnosza sie do 
//godzin na zegarze - w ten sposob okreslany jest kierunek
//iteruj po tablicy poziomo
const iterate9_3 = function(a, anchorX, anchorY, sequenceLen){
	let seq = []

	for(let i=-sequenceLen;i<=sequenceLen;++i){
		if(anchorX + i >= 0 && anchorX + i < a[anchorY].length){
			seq.push(a[anchorY][anchorX+i])
		}else seq.push(".")
	}

	return seq
}

//iteruj po tablicy w dol
const iterate12_6 = function(a, anchorX, anchorY, sequenceLen){
	let seq = []

	for(let i=-sequenceLen;i<=sequenceLen;++i){
		if(anchorY + i >= 0 && anchorY + i < a.length){
			seq.push(a[anchorY+i][anchorX])
		}else seq.push(".")
	}

	return seq
}

//iteruj po tablicy po skosie w prawa strone
const iterate11_5 = function(a, anchorX, anchorY, sequenceLen){
	let seq = []

	for(let i=-sequenceLen;i<=sequenceLen;++i){
		if(anchorY + i < a.length && anchorX + i < a[anchorY].length &&
			anchorY + i >= 0 && anchorX + i >= 0){
			seq.push(a[anchorY+i][anchorX+i])
		}else seq.push(".")
	}

	return seq
}

//iteruj po tablicy po skosie w lewa strone
const iterate7_2 = function(a, anchorX, anchorY, sequenceLen){
	let seq = []

	for(let i=-sequenceLen;i<=sequenceLen;++i){
		if(anchorY + i < a.length && anchorX - i < a.length &&
			anchorY + i >= 0 && anchorX - i >= 0){
			seq.push(a[anchorY+i][anchorX-i])
		}else seq.push(".")
	}

	return seq	
}


const createArray = function(x, y){
	a = []
	for(let i=0;i<y;++i){
		let buf = []
		for(let j=0;j<x;++j){
			buf.push(0)
		}
		a.push(buf)
	}

	return a
}

//jesli maska istnieje to musi byc to macierz zawierajaca ssame zera lub jedynki o 
//takim samym rozmiarze jak a
const max2D = function(a, mask = undefined){
	let x = 0
	let y = 0
	let max = -1

	for(let i=0;i<a.length;++i){
		for(let j=0;j<a[i].length;++j){
			//let sum = sumOfArray(a[i][j])

			if(mask){
				if(mask[i][j] == 0) continue
			}

			let sum = a[i][j]
			if(sum > max){
				y = i
				x = j
				max = sum
			}
		}
	}

	return {"x":x, "y":y}
}

const sum2D = function(a1,a2) {
	let ret = createArray(size.x, size.y)


	for(let i=0;i<a1.length;++i){
		for(let j=0;j<a1[i].length;++j){
			ret[i][j] = a1[i][j] + a2[i][j]
		}
	}

	return ret
}

const multiply2D = function(a, factor){
	let ret = createArray(size.x, size.y)

	for(let i=0;i<a.length;++i){
		for(let j=0;j<a[i].length;++j){
			ret[i][j] = a[i][j] * factor
		}
	}

	return ret
}

//funckcja tworzy macierz w zlozona z jedynek i zer. jezeli wartosc pola w tablicy a
//jest wystarczajaco duza to w tablicy wyjsciowej pojawi sie jedynka
const treshold2D = function(a, treshold) {
	let maxPos = max2D(a)
	treshold = a[maxPos.y][maxPos.x] * treshold

	let ret = createArray(size.x, size.y)

	for(let i=0;i<a.length;++i){
		for(let j=0;j<a[i].length;++j){
			if(a[i][j] >= treshold)
				ret[i][j] = 1
			else ret[i][j] = 0
		}
	}

	return ret
}

const sumOfArray = function(a){
	let sum=0

	for(let i=0; i<a.length; ++i){
		sum+=a[i]
	}

	return sum
}


//funkcja sprawdza czy array zawiera tylko znaki character
const hasOnly = function(a, character){
	for(let i of a){
		if(i!=character) return false
	}

	return true
}

//funkcja zwraca true jezeli character wystapil chociaz raz
const hasOne = function(a, character){
	
	for(let i of a){
		if(i==character) return true
	}

	return false	
}


//funkcja zlicza ilosc wystapien znaku character
const countCharactes = function(a, character){
	let ret = 0
	for(let i of a){
		if(i==character) ret ++
	}

	return ret
}


const bidirectionalSequence = function(a, character, seqBrakeCharacter){
	let center = Math.floor(a.length/2)	

	let sum=0
	let count = 0	
	for(let i=0;i<a.length;++i){

		if(a[i] == seqBrakeCharacter && i < center) {
			count=0
			sum=0
		}
		else if(a[i] == seqBrakeCharacter) break
		else if(a[i] == character){
			count ++
			sum += Math.pow(a.length,2)- Math.pow(i - center,2)
		}
	}
 
	return sum*count
}













