import Vue from 'vue'
import Router from 'vue-router'
import HelloWorld from '@/components/HelloWorld'
import HIome from '../components/home'
import Home from '@/components/cs/Vome'
import details from '../components/details'
import Login from '@/components/cs/login.vue'
Vue.use(Router)

export default new Router({
  // mode:"history/hash",  history模式可以去掉#；使用默认的hash模式比较好。
  routes: [
    // {
    //   path: '/',
    //   name: 'HelloWorld',
    //   component: HelloWorld
    // },
    {path:'/HIome',
    name:'HIome',
    component:HIome,
    children:[
     { path:'/',component:details}
    ]
    },
    { path:'/',component:Home},
    { path:'/login',component:Login},
  ]
})
