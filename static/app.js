//jshint esversion6

// const express = require('express');
// const app = express();

// const axios = require('axios');
// const { response } = require('express');
const Http = new XMLHttpRequest();
const url='https://arduinoiotbot.herokuapp.com/';

Http.onreadystatechange = (e) => {
  console.log(Http.responseText)
  document.getElementById('status').innerText="Status: "+Http.responseText;

}

// const getData= document.getElementsByClassName('fetch')[0];
const upBtn= document.getElementsByClassName('up')[0];
const downBtn= document.getElementsByClassName('down')[0];
const leftBtn= document.getElementsByClassName('left')[0];
const rightBtn= document.getElementsByClassName('right')[0];


const getDataServer = () =>{
    // axios.get('https://arduinoiotbot.herokuapp.com/').then(response=>{
    //     console.log(response);
    // });
    Http.open("GET", url);
    Http.send()
};

const sendupData=()=>{
    // axios.get('https://arduinoiotbot.herokuapp.com/modify?move=w').then(response=>{
    //     console.log(response);
    // });
    getDataServer()
    
    Http.open("GET", url+"/modify?move=w");
    Http.send();
};
const sendDownData=()=>{
    // axios.get('https://arduinoiotbot.herokuapp.com/modify?move=s').then(response=>{
    //     console.log(response);
    // });
    getDataServer()
    
    Http.open("GET", url+"/modify?move=s");
    Http.send();
};
const sendLeftData=()=>{
    // axios.get('https://arduinoiotbot.herokuapp.com/modify?move=a').then(response=>{
    //     console.log(response);
    // });
    getDataServer()
    
    Http.open("GET", url+"/modify?move=a");
    Http.send();
};
const sendRightData=()=>{
    // axios.get('https://arduinoiotbot.herokuapp.com/modify?move=d').then(response=>{
    //     console.log(response);
    // });
    getDataServer()

    Http.open("GET", url+"/modify?move=d");
    Http.send();
};
upBtn.addEventListener('click',sendupData);
downBtn.addEventListener('click',sendDownData);
leftBtn.addEventListener('click',sendLeftData);
rightBtn.addEventListener('click',sendRightData);