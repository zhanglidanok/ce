// The Vue build version to load with the `import` command
// (runtime-only or standalone) has been set in webpack.base.conf with an alias.
import Vue from 'vue'
import App from './App'
import router from './router'
import axios from 'axios'
import qs from 'qs'
Vue.prototype.qs=qs
Vue.config.productionTip = false
Vue.prototype.axios=axios
axios.defaults.withCredentials=true
// axios.defaults.baseUrl='http://127.0.0.1:3000/'
axios.defaults.baseURL="http://127.0.0.1:3000/"
/* eslint-disable no-new */
// import Header from './components/header.vue'
// Vue.component('Header',Header)
import MintUI from 'mint-ui'
import 'mint-ui/lib/style.css'
// import './assets/base.css'
Vue.use(MintUI)
new Vue({
  el: '#app',
  router,
  components: { App },
  template: '<App/>'
})
